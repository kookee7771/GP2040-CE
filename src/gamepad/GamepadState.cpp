#include "GamepadState.h"
#include "drivermanager.h"

// Convert the horizontal GamepadState dpad axis value into an analog value
uint16_t dpadToAnalogX(uint8_t dpad)
{
	switch (dpad & (GAMEPAD_MASK_LEFT | GAMEPAD_MASK_RIGHT))
	{
		case GAMEPAD_MASK_LEFT:
			return GAMEPAD_JOYSTICK_MIN;

		case GAMEPAD_MASK_RIGHT:
			return GAMEPAD_JOYSTICK_MAX;

		default:
			if ( DriverManager::getInstance().getDriver() != nullptr )
				return DriverManager::getInstance().getDriver()->GetJoystickMidValue();
			else
				return GAMEPAD_JOYSTICK_MID;
	}
}

// Convert the vertical GamepadState dpad axis value into an analog value
uint16_t dpadToAnalogY(uint8_t dpad)
{
	switch (dpad & (GAMEPAD_MASK_UP | GAMEPAD_MASK_DOWN))
	{
		case GAMEPAD_MASK_UP:
			return GAMEPAD_JOYSTICK_MIN;

		case GAMEPAD_MASK_DOWN:
			return GAMEPAD_JOYSTICK_MAX;

		default:
			if ( DriverManager::getInstance().getDriver() != nullptr )
				return DriverManager::getInstance().getDriver()->GetJoystickMidValue();
			else
				return GAMEPAD_JOYSTICK_MID;
	}
}

uint8_t getMaskFromDirection(DpadDirection direction)
{
	return dpadMasks[direction-1];
}

uint8_t updateDpad(uint8_t dpad, DpadDirection direction)
{
	static bool inList[] = {false, false, false, false, false}; // correspond to DpadDirection: none, up, down, left, right
	static list<DpadDirection> dpadList;

	if(dpad & getMaskFromDirection(direction))
	{
		if(!inList[direction])
		{
			dpadList.push_back(direction);
			inList[direction] = true;
		}
	}
	else
	{
		if(inList[direction])
		{
			dpadList.remove(direction);
			inList[direction] = false;
		}
	}

	if(dpadList.empty()) {
		return 0;
	}
	else {
		return getMaskFromDirection(dpadList.back());
	}
}

/**
 * @brief Filter diagonals out of the dpad, making the device work as a 4-way lever.
 *
 * The most recent cardinal direction wins.
 *
 * @param dpad The GameState.dpad value.
 * @return uint8_t The new dpad value.
 */
uint8_t filterToFourWayMode(uint8_t dpad)
{
	updateDpad(dpad, DIRECTION_UP);
	updateDpad(dpad, DIRECTION_DOWN);
	updateDpad(dpad, DIRECTION_LEFT);
	return updateDpad(dpad, DIRECTION_RIGHT);
}

/**
 * @brief Run SOCD cleaning against a D-pad value.
 *
 * @param mode The SOCD cleaning mode.
 * @param dpad The GamepadState.dpad value.
 * @return uint8_t The clean D-pad value.
 */
uint8_t runSOCDCleaner(SOCDMode mode, uint8_t dpad)
{
    if (mode == SOCD_MODE_BYPASS) {
        return dpad;
    }

    static DpadDirection lastUD = DIRECTION_NONE;
    static DpadDirection lastLR = DIRECTION_NONE;
    static uint32_t lastDirectionChangeTime = 0;
    static uint8_t lastLeftRightState = 0;
    uint8_t newDpad = 0;

    // 상하 SOCD 처리 (이 부분은 변경 없음)
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

    // 좌우 SOCD 처리 - 여기를 수정
    uint8_t currentLRState = dpad & (GAMEPAD_MASK_LEFT | GAMEPAD_MASK_RIGHT);
    uint32_t currentTime = getMillis();

    // 좌우 상태가 변경되었는지 확인
    if (currentLRState != lastLeftRightState) {
        // 상태가 변경되면 타임스탬프 업데이트
        lastDirectionChangeTime = currentTime;
        lastLeftRightState = currentLRState;
        
        // 중립으로 한 프레임 강제 처리 (좌우 변경 시에만)
        if ((currentLRState == GAMEPAD_MASK_LEFT && (lastLR == DIRECTION_RIGHT)) || 
            (currentLRState == GAMEPAD_MASK_RIGHT && (lastLR == DIRECTION_LEFT))) {
            lastLR = DIRECTION_NONE;
            return newDpad; // 중립 상태로 즉시 반환
        }
    }

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
