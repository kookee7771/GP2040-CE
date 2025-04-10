uint8_t runSOCDCleaner(SOCDMode mode, uint8_t dpad)
{
    if (mode == SOCD_MODE_BYPASS) {
        return dpad;
    }
    
    static DpadDirection lastUD = DIRECTION_NONE;
    static DpadDirection lastLR = DIRECTION_NONE;
    static uint32_t lastDirectionChangeTime = 0;
    static uint8_t lastLeftRightState = 0;
    static bool forceNeutralState = false;
    static uint32_t neutralDuration = 0;  // 중립 상태 지속 시간 추적용
    
    uint8_t newDpad = 0;
    uint32_t currentTime = getMillis();
    
    // 상하 SOCD 처리 (변경 없음)
    switch (dpad & (GAMEPAD_MASK_UP | GAMEPAD_MASK_DOWN))
    {
        case (GAMEPAD_MASK_UP | GAMEPAD_MASK_DOWN):
            if (mode == SOCD_MODE_UP_PRIORITY)
            {
                newDpad |= GAMEPAD_MASK_UP;
                lastUD = DIRECTION_UP;
            }
            else if (mode == SOCD_MODE_SECOND_INPUT_PRIORITY && lastUD != DIRECTION_NONE)
                newDpad |= (lastUD == DIRECTION_UP) ? GAMEPAD_MASK_DOWN : GAMEPAD_MASK_UP;
            else if (mode == SOCD_MODE_FIRST_INPUT_PRIORITY && lastUD != DIRECTION_NONE)
                newDpad |= (lastUD == DIRECTION_UP) ? GAMEPAD_MASK_UP : GAMEPAD_MASK_DOWN;
            else
                lastUD = DIRECTION_NONE;
            break;
        
        case GAMEPAD_MASK_UP:
            newDpad |= GAMEPAD_MASK_UP;
            lastUD = DIRECTION_UP;
            break;
        
        case GAMEPAD_MASK_DOWN:
            newDpad |= GAMEPAD_MASK_DOWN;
            lastUD = DIRECTION_DOWN;
            break;
        
        default:
            lastUD = DIRECTION_NONE;
            break;
    }
    
    // 좌우 SOCD 처리 - 개선된 중립 상태 관리
    uint8_t currentLRState = dpad & (GAMEPAD_MASK_LEFT | GAMEPAD_MASK_RIGHT);
    
    // 중립 상태 강제 기간 확인
    if (forceNeutralState) {
        // 중립 상태 기간이 10ms(약 1프레임 이상) 지속되었는지 확인
        if (currentTime - neutralDuration >= 10) {
            forceNeutralState = false;  // 중립 상태 종료
        } else {
            // 중립 상태 유지
            lastLR = DIRECTION_NONE;
            return newDpad;  // 중립 상태로 즉시 반환 (좌우 버튼 없음)
        }
    }
    
    // 좌우 상태 변경 감지
    if (currentLRState != lastLeftRightState) {
        // 특히 방향 전환 (좌->우 또는 우->좌)인 경우 중립 상태 강제
        if ((currentLRState == GAMEPAD_MASK_LEFT && lastLR == DIRECTION_RIGHT) || 
            (currentLRState == GAMEPAD_MASK_RIGHT && lastLR == DIRECTION_LEFT)) {
            forceNeutralState = true;
            neutralDuration = currentTime;
            lastLR = DIRECTION_NONE;
            lastLeftRightState = currentLRState;
            return newDpad;  // 중립 상태 반환
        }
        
        lastDirectionChangeTime = currentTime;
        lastLeftRightState = currentLRState;
    }
    
    // 일반적인 좌우 처리
    switch (currentLRState)
    {
        case (GAMEPAD_MASK_LEFT | GAMEPAD_MASK_RIGHT):
            if (mode == SOCD_MODE_SECOND_INPUT_PRIORITY && lastLR != DIRECTION_NONE)
                newDpad |= (lastLR == DIRECTION_LEFT) ? GAMEPAD_MASK_RIGHT : GAMEPAD_MASK_LEFT;
            else if (mode == SOCD_MODE_FIRST_INPUT_PRIORITY && lastLR != DIRECTION_NONE)
                newDpad |= (lastLR == DIRECTION_LEFT) ? GAMEPAD_MASK_LEFT : GAMEPAD_MASK_RIGHT;
            else
                lastLR = DIRECTION_NONE;
            break;
        
        case GAMEPAD_MASK_LEFT:
            newDpad |= GAMEPAD_MASK_LEFT;
            lastLR = DIRECTION_LEFT;
            break;
        
        case GAMEPAD_MASK_RIGHT:
            newDpad |= GAMEPAD_MASK_RIGHT;
            lastLR = DIRECTION_RIGHT;
            break;
        
        default:
            lastLR = DIRECTION_NONE;
            break;
    }
    
    return newDpad;
}
