// This example is taken from:
// https://github.com/tinkertechtrove/pico-pi-playing/blob/main/pio-steppers/test_motor4.py

// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// ------ //
// tester //
// ------ //

#define tester_wrap_target 0
#define tester_wrap 9

static const uint16_t tester_program_instructions[] = {
    //     .wrap_target
    0x80a0, //  0: pull   block
    0xa027, //  1: mov    x, osr
    0x80a0, //  2: pull   block
    0xa047, //  3: mov    y, osr
    0x0029, //  4: jmp    !x, 9
    0x00e7, //  5: jmp    !osre, 7
    0xa0e2, //  6: mov    osr, y
    0x7f04, //  7: out    pins, 4                [31]
    0x0045, //  8: jmp    x--, 5
    0xc000, //  9: irq    nowait 0
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program tester_program = {
    .instructions = tester_program_instructions,
    .length = 10,
    .origin = -1,
};

static inline pio_sm_config tester_program_get_default_config(uint offset)
{
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + tester_wrap_target, offset + tester_wrap);
    return c;
}
#endif
