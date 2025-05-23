/*
 * SPDX-FileCopyrightText: 2024 M5Stack Technology CO LTD
 *
 * SPDX-License-Identifier: MIT
 */
#pragma once
#include "../../../../../hal/hal.h"
#include "m5unified/Button_Class.hpp"

namespace SYSTEM {
namespace INPUTS {
/**
 * @brief Button class with richer apis
 *
 */
class Button : public m5::Button_Class {
private:
    GAMEPAD::GamePadButton_t _button;

public:
    Button(GAMEPAD::GamePadButton_t button) : _button(button)
    {
    }
    void update();

public:
    /**
     * @brief Button instances
     *
     * @return Button*
     */
    static Button* A();
    static Button* B();

    /**
     * @brief Helper method to update all button instances
     *
     */
    static void Update();
};

}  // namespace INPUTS
}  // namespace SYSTEM
