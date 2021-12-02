/// @copyright gm 2021

#include "register_types.h"

#include "core/reference.h"
#include "serial.h"

void register_serial_types() {
    ClassDB::register_class<Serial>();
}

void unregister_serial_types() {
   // Nothing to do here in this example.
}
