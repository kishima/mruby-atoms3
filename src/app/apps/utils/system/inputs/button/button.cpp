/*
 * SPDX-FileCopyrightText: 2024 M5Stack Technology CO LTD
 *
 * SPDX-License-Identifier: MIT
 */
#include "button.h"
#include "../../../../../hal/hal.h"

using namespace SYSTEM::INPUTS;

void Button::update()
{
    m5::Button_Class::setRawState(HAL::Millis(), HAL::GetButton(_button));
}

static Button* _button_a = nullptr;
Button* Button::A()
{
    // Lazy loading
    if (_button_a == nullptr) _button_a = new Button(GAMEPAD::BTN_A);
    return _button_a;
}

static Button* _button_b = nullptr;
Button* Button::B()
{
    // Lazy loading
    if (_button_b == nullptr) _button_b = new Button(GAMEPAD::BTN_B);
    return _button_b;
}

void Button::Update()
{
    A()->update();
    B()->update();
}
