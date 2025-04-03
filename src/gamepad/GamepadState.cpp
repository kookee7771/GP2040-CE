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
 // 중립 감지를 위한 구조체
struct NeutralTracker {
	uint32_t lastInputTime = 0;
	DpadDirection lastDirection = DIRECTION_NONE;
	const uint32_t NEUTRAL_THRESHOLD_MS = 10; // 중립 인식 시간 (ms)
};

// 전역 중립 트래커
static NeutralTracker upDownTracker;
static NeutralTracker leftRightTracker;

uint8_t runSOCDCleaner(SOCDMode mode, uint8_t dpad)
{
	// Bypass 모드일 경우 그대로 반환
	if (mode == SOCD_MODE_BYPASS) {
		return dpad;
	}

	uint32_t currentTime = getMillis();
	uint8_t newDpad = 0;

	// 상하 방향 처리
	switch (dpad & (GAMEPAD_MASK_UP | GAMEPAD_MASK_DOWN))
	{
	case (GAMEPAD_MASK_UP | GAMEPAD_MASK_DOWN):
		// 빠른 연속 입력 시 중립 상태 처리
		if (currentTime - upDownTracker.lastInputTime <= upDownTracker.NEUTRAL_THRESHOLD_MS) {
			newDpad = 0;
			upDownTracker.lastDirection = DIRECTION_NONE;
		}
		else {
			// 기존 SOCD 로직
			if (mode == SOCD_MODE_UP_PRIORITY)
			{
				newDpad |= GAMEPAD_MASK_UP;
				upDownTracker.lastDirection = DIRECTION_UP;
			}
			else if (mode == SOCD_MODE_SECOND_INPUT_PRIORITY && upDownTracker.lastDirection != DIRECTION_NONE)
				newDpad |= (upDownTracker.lastDirection == DIRECTION_UP) ? GAMEPAD_MASK_DOWN : GAMEPAD_MASK_UP;
			else if (mode == SOCD_MODE_FIRST_INPUT_PRIORITY && upDownTracker.lastDirection != DIRECTION_NONE)
				newDpad |= (upDownTracker.lastDirection == DIRECTION_UP) ? GAMEPAD_MASK_UP : GAMEPAD_MASK_DOWN;
			else
				upDownTracker.lastDirection = DIRECTION_NONE;
		}
		break;
	case GAMEPAD_MASK_UP:
		newDpad |= GAMEPAD_MASK_UP;
		upDownTracker.lastDirection = DIRECTION_UP;
		upDownTracker.lastInputTime = currentTime;
		break;
	case GAMEPAD_MASK_DOWN:
		newDpad |= GAMEPAD_MASK_DOWN;
		upDownTracker.lastDirection = DIRECTION_DOWN;
		upDownTracker.lastInputTime = currentTime;
		break;
	default:
		upDownTracker.lastDirection = DIRECTION_NONE;
		break;
	}

	// 좌우 방향 처리
	switch (dpad & (GAMEPAD_MASK_LEFT | GAMEPAD_MASK_RIGHT))
	{
	case (GAMEPAD_MASK_LEFT | GAMEPAD_MASK_RIGHT):
		// 빠른 연속 입력 시 중립 상태 처리
		if (currentTime - leftRightTracker.lastInputTime <= leftRightTracker.NEUTRAL_THRESHOLD_MS) {
			newDpad &= ~(GAMEPAD_MASK_LEFT | GAMEPAD_MASK_RIGHT);
			leftRightTracker.lastDirection = DIRECTION_NONE;
		}
		else {
			// 기존 SOCD 로직
			if (mode == SOCD_MODE_SECOND_INPUT_PRIORITY && leftRightTracker.lastDirection != DIRECTION_NONE)
				newDpad |= (leftRightTracker.lastDirection == DIRECTION_LEFT) ? GAMEPAD_MASK_RIGHT : GAMEPAD_MASK_LEFT;
			else if (mode == SOCD_MODE_FIRST_INPUT_PRIORITY && leftRightTracker.lastDirection != DIRECTION_NONE)
				newDpad |= (leftRightTracker.lastDirection == DIRECTION_LEFT) ? GAMEPAD_MASK_LEFT : GAMEPAD_MASK_RIGHT;
			else
				leftRightTracker.lastDirection = DIRECTION_NONE;
		}
		break;
	case GAMEPAD_MASK_LEFT:
		newDpad |= GAMEPAD_MASK_LEFT;
		leftRightTracker.lastDirection = DIRECTION_LEFT;
		leftRightTracker.lastInputTime = currentTime;
		break;
	case GAMEPAD_MASK_RIGHT:
		newDpad |= GAMEPAD_MASK_RIGHT;
		leftRightTracker.lastDirection = DIRECTION_RIGHT;
		leftRightTracker.lastInputTime = currentTime;
		break;
	default:
		leftRightTracker.lastDirection = DIRECTION_NONE;
		break;
	}

	return newDpad;
}
