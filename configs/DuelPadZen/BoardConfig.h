/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: Copyright (c) 2024 OpenStickCommunity (gp2040-ce.info)
 */

#ifndef PICO_BOARD_CONFIG_H_
#define PICO_BOARD_CONFIG_H_

 #include "enums.pb.h"
 #include "class/hid/hid.h"
 #define BOARD_CONFIG_LABEL "DuelPadZen"
 
 // Main pin mapping Configuration
 // Mapping between Flatbox Rev4 switch number (as silkscreened) and GPIO pin listed under "Flatbox Rev4 SW#"
 //                                             //SW# | GP2040 | Xinput | Switch  | PS3/4/5  | Dinput | Arcade |
 #define GPIO_PIN_16 GpioAction::BUTTON_PRESS_UP     // UP     | UP     | UP      | UP       | UP     | UP     |
 #define GPIO_PIN_10 GpioAction::BUTTON_PRESS_DOWN   // DOWN   | DOWN   | DOWN    | DOWN     | DOWN   | DOWN   |
 #define GPIO_PIN_11 GpioAction::BUTTON_PRESS_RIGHT  // RIGHT  | RIGHT  | RIGHT   | RIGHT    | RIGHT  | RIGHT  |
 #define GPIO_PIN_09 GpioAction::BUTTON_PRESS_LEFT   // LEFT   | LEFT   | LEFT    | LEFT     | LEFT   | LEFT   |
 #define GPIO_PIN_19 GpioAction::BUTTON_PRESS_B1     // B1     | A      | B       | Cross    | 2      | K1     |
 #define GPIO_PIN_24 GpioAction::BUTTON_PRESS_B2     // B2     | B      | A       | Circle   | 3      | K2     |
 #define GPIO_PIN_26 GpioAction::BUTTON_PRESS_R2     // R2     | RT     | ZR      | R2       | 8      | K3     |
 #define GPIO_PIN_28 GpioAction::BUTTON_PRESS_L2     // L2     | LT     | ZL      | L2       | 7      | K4     |
 #define GPIO_PIN_18 GpioAction::BUTTON_PRESS_B3     // B3     | X      | Y       | Square   | 1      | P1     |
 #define GPIO_PIN_25 GpioAction::BUTTON_PRESS_B4     // B4     | Y      | X       | Triangle | 4      | P2     |
 #define GPIO_PIN_27 GpioAction::BUTTON_PRESS_R1     // R1     | RB     | R       | R1       | 6      | P3     |
 #define GPIO_PIN_29 GpioAction::BUTTON_PRESS_L1     // L1     | LB     | L       | L1       | 5      | P4     |
 #define GPIO_PIN_05 GpioAction::BUTTON_PRESS_S1     // S1     | Back   | Minus   | Select   | 9      | Coin   |
 #define GPIO_PIN_06 GpioAction::BUTTON_PRESS_S2     // S2     | Start  | Plus    | Start    | 10     | Start  |
 #define GPIO_PIN_02 GpioAction::BUTTON_PRESS_L3     // L3     | LS     | LS      | L3       | 11     | LS     |
 #define GPIO_PIN_01 GpioAction::BUTTON_PRESS_R3     // R3     | RS     | RS      | R3       | 12     | RS     |
 #define GPIO_PIN_04 GpioAction::BUTTON_PRESS_A1     // A1     | Guide  | Home    | PS       | 13     | ~      |
 #define GPIO_PIN_07 GpioAction::BUTTON_PRESS_UP     // UP     | UP     | UP      | UP       | UP     | UP     |


 #define GPIO_PIN_17 GpioAction::MENU_NAVIGATION_UP     // UP
 #define GPIO_PIN_13 GpioAction::MENU_NAVIGATION_DOWN   // DOWN
 #define GPIO_PIN_08 GpioAction::MENU_NAVIGATION_LEFT   // LEFT
 #define GPIO_PIN_14 GpioAction::MENU_NAVIGATION_RIGHT  // RIGHT
 #define GPIO_PIN_12 GpioAction::MENU_NAVIGATION_SELECT // PRESS

 #define GPIO_PIN_03 GpioAction::BUTTON_PRESS_MACRO_2
 
 
 // Keyboard Mapping Configuration
 //                                            // GP2040 | Xinput | Switch  | PS3/4/5  | Dinput | Arcade |
 #define KEY_DPAD_UP     HID_KEY_ARROW_UP      // UP     | UP     | UP      | UP       | UP     | UP     |
 #define KEY_DPAD_DOWN   HID_KEY_ARROW_DOWN    // DOWN   | DOWN   | DOWN    | DOWN     | DOWN   | DOWN   |
 #define KEY_DPAD_RIGHT  HID_KEY_ARROW_RIGHT   // RIGHT  | RIGHT  | RIGHT   | RIGHT    | RIGHT  | RIGHT  |
 #define KEY_DPAD_LEFT   HID_KEY_ARROW_LEFT    // LEFT   | LEFT   | LEFT    | LEFT     | LEFT   | LEFT   |
 #define KEY_BUTTON_B1   HID_KEY_SHIFT_LEFT    // B1     | A      | B       | Cross    | 2      | K1     |
 #define KEY_BUTTON_B2   HID_KEY_Z             // B2     | B      | A       | Circle   | 3      | K2     |
 #define KEY_BUTTON_R2   HID_KEY_X             // R2     | RT     | ZR      | R2       | 8      | K3     |
 #define KEY_BUTTON_L2   HID_KEY_V             // L2     | LT     | ZL      | L2       | 7      | K4     |
 #define KEY_BUTTON_B3   HID_KEY_CONTROL_LEFT  // B3     | X      | Y       | Square   | 1      | P1     |
 #define KEY_BUTTON_B4   HID_KEY_ALT_LEFT      // B4     | Y      | X       | Triangle | 4      | P2     |
 #define KEY_BUTTON_R1   HID_KEY_SPACE         // R1     | RB     | R       | R1       | 6      | P3     |
 #define KEY_BUTTON_L1   HID_KEY_C             // L1     | LB     | L       | L1       | 5      | P4     |
 #define KEY_BUTTON_S1   HID_KEY_5             // S1     | Back   | Minus   | Select   | 9      | Coin   |
 #define KEY_BUTTON_S2   HID_KEY_1             // S2     | Start  | Plus    | Start    | 10     | Start  |
 #define KEY_BUTTON_L3   HID_KEY_EQUAL         // L3     | LS     | LS      | L3       | 11     | LS     |
 #define KEY_BUTTON_R3   HID_KEY_MINUS         // R3     | RS     | RS      | R3       | 12     | RS     |
 #define KEY_BUTTON_A1   HID_KEY_9             // A1     | Guide  | Home    | PS       | 13     | ~      |
 #define KEY_BUTTON_A2   HID_KEY_F2            // A2     | ~      | Capture | ~        | 14     | ~      |
 
 // Setting GPIO pins to assigned by add-on
 #define GPIO_PIN_15 GpioAction::ASSIGNED_TO_ADDON
 
 #define USB_PERIPHERAL_ENABLED 1
 #define USB_PERIPHERAL_PIN_DPLUS 22
 #define USB_PERIPHERAL_PIN_ORDER 0
 
 #define TURBO_ENABLED 1
 #define GPIO_PIN_00 GpioAction::BUTTON_PRESS_TURBO
 
 #define DEFAULT_INPUT_MODE_R1 INPUT_MODE_XBONE
 #define DEFAULT_INPUT_MODE_R2 INPUT_MODE_KEYBOARD
 #define DEFAULT_INPUT_MODE_B4 INPUT_MODE_PS5
 #define DEFAULT_INPUT_MODE_B3 INPUT_MODE_XINPUT
 #define DEFAULT_INPUT_MODE_B2 INPUT_MODE_GENERIC
 #define DEFAULT_INPUT_MODE_B1 INPUT_MODE_SWITCH
 #define DEFAULT_INPUT_MODE_L2 INPUT_MODE_PS4
 
 #define DEFAULT_PS5AUTHENTICATION_TYPE INPUT_MODE_AUTH_TYPE_USB
 #define XBONEPASSTHROUGH_ENABLED 1
 
 #define FOCUS_MODE_ENABLED 1
 #define FOCUS_MODE_MACRO_LOCK_ENABLED 1
 #define FOCUS_MODE_BUTTON_MASK GAMEPAD_MASK_S1 | GAMEPAD_MASK_S2 | GAMEPAD_MASK_A1 | GAMEPAD_MASK_A2 | GAMEPAD_MASK_L3 | GAMEPAD_MASK_R3
 
 #define BOARD_LEDS_PIN 15
 #define LEDS_THEME_INDEX 20
 #define LED_BRIGHTNESS_MAXIMUM 255
 #define LED_BRIGHTNESS_STEPS 5
 #define LEDS_BRIGHTNESS 2
 #define LED_FORMAT LED_FORMAT_GRB
 #define LEDS_PER_PIXEL 2
 #define LEDS_BASE_ANIMATION_INDEX 1
 #define LEDS_STATIC_COLOR_INDEX 2
 
 #define LEDS_DPAD_LEFT   0  
 #define LEDS_DPAD_DOWN   1
 #define LEDS_DPAD_RIGHT  2
 #define LEDS_BUTTON_B3   3
 #define LEDS_BUTTON_B4   4
 #define LEDS_BUTTON_R1   5
 #define LEDS_BUTTON_L1   6
 #define LEDS_BUTTON_L2   7
 #define LEDS_BUTTON_R2   8
 #define LEDS_BUTTON_B2   9
 #define LEDS_BUTTON_B1   10
 #define LEDS_BUTTON_R3   11
 #define LEDS_BUTTON_L3   12
 #define LEDS_DPAD_UP     13
 #define LEDS_BUTTON_A1   14
 #define LEDS_BUTTON_A2   15

 #define HAS_I2C_DISPLAY 1
 #define I2C0_ENABLED 1
 #define I2C0_PIN_SDA 20
 #define I2C0_PIN_SCL 21
 
 #define SPLASH_MODE SPLASH_MODE_STATIC
 #define SPLASH_DURATION 2500
 
 // Keyboard Host enabled by default
 #define KEYBOARD_HOST_ENABLED 1
 
 #define DUAL_DIRECTIONAL_ENABLED 1

 #define BUTTON_LAYOUT BUTTON_LAYOUT_BOARD_DEFINED_A
 #define BUTTON_LAYOUT_RIGHT BUTTON_LAYOUT_BOARD_DEFINED_B

 #define DEFAULT_BOARD_LAYOUT_A {\
        {GP_ELEMENT_PIN_BUTTON, {44, 18,  4,  4, 1, 0, 7,    GP_SHAPE_ELLIPSE}},\
        {GP_ELEMENT_DIR_BUTTON, {32, 27,  4,  4, 1, 1, GAMEPAD_MASK_LEFT,  GP_SHAPE_ELLIPSE}},\
        {GP_ELEMENT_DIR_BUTTON, {42, 28,  4,  4, 1, 1, GAMEPAD_MASK_DOWN,  GP_SHAPE_ELLIPSE}},\
        {GP_ELEMENT_DIR_BUTTON, {50, 33,  4,  4, 1, 1, GAMEPAD_MASK_RIGHT, GP_SHAPE_ELLIPSE}},\
        {GP_ELEMENT_DIR_BUTTON, {52, 49,  5,  5, 1, 1, GAMEPAD_MASK_UP,    GP_SHAPE_ELLIPSE}},\
         {GP_ELEMENT_BTN_BUTTON, {70, 49,  5,  5, 1, 1, GAMEPAD_MASK_L3,   GP_SHAPE_ELLIPSE}},\
        {GP_ELEMENT_PIN_BUTTON, {41, 47,  4,  4, 1, 0, 3,                  GP_SHAPE_ELLIPSE}},\
        {GP_ELEMENT_BTN_BUTTON, {81, 45,  4,  4, 1, 1, GAMEPAD_MASK_R3,    GP_SHAPE_ELLIPSE}},\
        {GP_ELEMENT_PIN_BUTTON, {14, 14,  2,  2, 1, 1, 0,                  GP_SHAPE_ELLIPSE}},\
        {GP_ELEMENT_BTN_BUTTON, {19, 14,  2,  2, 1, 1, GAMEPAD_MASK_A1,    GP_SHAPE_ELLIPSE}},\
        {GP_ELEMENT_BTN_BUTTON, {109, 14,  2,  2, 1, 1, GAMEPAD_MASK_S2,   GP_SHAPE_ELLIPSE}},\
        {GP_ELEMENT_BTN_BUTTON, {114, 14,  2,  2, 1, 1, GAMEPAD_MASK_S1,   GP_SHAPE_ELLIPSE}}\
 }

 #define DEFAULT_BOARD_LAYOUT_B {\
    {GP_ELEMENT_BTN_BUTTON, {68, 21, 4, 4, 1, 1, GAMEPAD_MASK_B3,     GP_SHAPE_ELLIPSE}},\
    {GP_ELEMENT_BTN_BUTTON, {79, 19, 4, 4, 1, 1, GAMEPAD_MASK_B4,     GP_SHAPE_ELLIPSE}},\
    {GP_ELEMENT_BTN_BUTTON, {89, 18, 4, 4, 1, 1, GAMEPAD_MASK_R1,     GP_SHAPE_ELLIPSE}},\
    {GP_ELEMENT_BTN_BUTTON, {99, 20, 4, 4, 1, 1, GAMEPAD_MASK_L1,     GP_SHAPE_ELLIPSE}},\
    {GP_ELEMENT_BTN_BUTTON, {69, 30, 4, 4, 1, 1, GAMEPAD_MASK_B1,     GP_SHAPE_ELLIPSE}},\
    {GP_ELEMENT_BTN_BUTTON, {79, 29, 4, 4, 1, 1, GAMEPAD_MASK_B2,     GP_SHAPE_ELLIPSE}},\
    {GP_ELEMENT_BTN_BUTTON, {89, 28, 4, 4, 1, 1, GAMEPAD_MASK_R2,     GP_SHAPE_ELLIPSE}},\
    {GP_ELEMENT_BTN_BUTTON, {99, 30, 4, 4, 1, 1, GAMEPAD_MASK_L2,     GP_SHAPE_ELLIPSE}}\
 }
 
 #define DEFAULT_SPLASH \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xE0,0x07,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xE0,0x07,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xE0,0x07,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xE7,0xE7,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0xE7,0xE7,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x07,0xE0,0x00,0xFE,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x07,0xE0,0x00,0x7E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0x7F,0x07,0xE0,0xFE,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0x7F,0x87,0xE0,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0x87,0xE1,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7C,0x7F,0x07,0xE0,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7E,0x3E,0x07,0xE0,0x7C,0x7E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x07,0xE0,0x00,0x7E,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x07,0xE0,0x00,0xFE,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0xE7,0xE7,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xE7,0xE7,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xE0,0x07,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x0F,0xFF,0xE0,0x07,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xE0,0x07,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0xFF,0xFF,0x1E,0x00,0x7B,0xFF,0xFF,0x78,0x00,0x0F,0xFF,0xF0,0x3C,0x03,0xFF,0xFC, \
 0xFF,0xFF,0x9E,0x00,0x7B,0xFF,0xFF,0x78,0x00,0x0F,0xFF,0xF8,0x1E,0x03,0xFF,0xFE, \
 0xFF,0xFF,0xDE,0x00,0x7B,0xFF,0xFF,0x78,0x00,0x0F,0xFF,0xFC,0x1E,0x03,0xFF,0xFF, \
 0x00,0x07,0xDE,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x00,0x3C,0x1F,0x00,0x00,0x1F, \
 0x00,0x03,0xDE,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x00,0x1C,0x0F,0x00,0x00,0x0F, \
 0x00,0x03,0xDE,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x00,0x3C,0x0F,0x00,0x00,0x0F, \
 0x00,0x03,0xDE,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x00,0x3C,0x07,0x80,0x00,0x0F, \
 0xF0,0x03,0xDE,0x00,0x7B,0xFF,0xFC,0x78,0x00,0x0F,0xFF,0xFD,0xE7,0x83,0xC0,0x0F, \
 0xF0,0x03,0xDE,0x00,0x7B,0xFF,0xFC,0x78,0x00,0x0F,0xFF,0xF9,0xE3,0xC3,0xC0,0x0F, \
 0xF0,0x03,0xDE,0x00,0x7B,0xFF,0xFC,0x78,0x00,0x0F,0xFF,0xF3,0xFF,0xC3,0xC0,0x0F, \
 0xF0,0x03,0xDE,0x00,0x7B,0xC0,0x00,0x78,0x00,0x0F,0x00,0x03,0xFF,0xE3,0xC0,0x0F, \
 0xF0,0x03,0xDE,0x00,0x7B,0xC0,0x00,0x78,0x00,0x0F,0x00,0x07,0xFF,0xE3,0xC0,0x0F, \
 0xF0,0x03,0xDE,0x00,0x7B,0xC0,0x00,0x78,0x00,0x0F,0x00,0x07,0xFF,0xE3,0xC0,0x0F, \
 0xF0,0x07,0xDE,0x00,0xFB,0xC0,0x00,0x78,0x00,0x0F,0x00,0x0F,0x80,0xF3,0xC0,0x1F, \
 0xFF,0xFF,0xDF,0xE7,0xFB,0xFF,0xFF,0x7F,0xFF,0xEF,0x00,0x0F,0x00,0xF3,0xFF,0xFF, \
 0xFF,0xFF,0x8F,0xE7,0xF3,0xFF,0xFF,0x7F,0xFF,0xEF,0x00,0x0F,0x00,0x7B,0xFF,0xFE, \
 0xFF,0xFF,0x07,0xE7,0xE3,0xFF,0xFF,0x7F,0xFF,0xEF,0x00,0x1E,0x00,0x7B,0xFF,0xFC, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, \
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
 
 #endif