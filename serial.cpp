/// @copyright gm 2021

#include "serial.h"

// Serial library
#include <serialib.h>

void Serial::add(int p_value) {
    count += p_value;
}

void Serial::reset() {
    count = 0;
}

int Serial::get_total() const {
    return count;
}

void Serial::_bind_methods() {
    ClassDB::bind_method(D_METHOD("add", "value"), &Serial::add);
    ClassDB::bind_method(D_METHOD("reset"), &Serial::reset);
    ClassDB::bind_method(D_METHOD("get_total"), &Serial::get_total);
}

Serial::Serial() {
    count = 0;
}
