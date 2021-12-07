/// @copyright gm 2021

#include "serial.h"

static const unsigned int kSerialTimeoutMs = 250;

void Serial::write_char(int value) {
	if (serial.writeChar(value) <= 0)
	{
		ERR_PRINT("Serial lib: could not write anything over the serial port\n");
	}
}

int Serial::read_char() {
	char tmp;
	if (serial.readChar(&tmp, kSerialTimeoutMs) <= 0)
	{
		ERR_PRINT("Serial lib: could not write anything over the serial port\n");
	}
	return (int)tmp;
}

void Serial::write_string(const String& value) {
	CharString ascii_value = value.ascii();
	if (serial.writeString(ascii_value.ptr()) <= 0)
	{
		ERR_PRINT("Serial lib: could not write anything over the serial port\n");
	}
}

String Serial::read_string() {
	CharString ascii_value;
	ascii_value.resize(256);
	// Expecting "newline" character at the end of the sentence
	if (serial.readString(ascii_value.ptrw(), 10, 256, kSerialTimeoutMs) > 0)
	{
		return String(ascii_value.ptr());
	} else {
		ERR_PRINT("Serial lib: could not read anything over the serial port\n");
	}
	return String();
}

int Serial::available()
{
	return serial.available();
}

void Serial::_bind_methods() {
    ClassDB::bind_method(D_METHOD("write_char", "value"), &Serial::write_char);
    ClassDB::bind_method(D_METHOD("read_char"), &Serial::read_char);
		ClassDB::bind_method(D_METHOD("write_string", "value"), &Serial::write_string);
		ClassDB::bind_method(D_METHOD("read_string"), &Serial::read_string);
		ClassDB::bind_method(D_METHOD("available"), &Serial::available);
		ClassDB::bind_method(D_METHOD("connect_to_serial_port", "value"), &Serial::connect_to_serial_port);
		ClassDB::bind_method(D_METHOD("is_serial_connected"), &Serial::is_serial_connected);
		ClassDB::bind_method(D_METHOD("disconnect_serial"), &Serial::disconnect_serial);
}

bool Serial::connect_to_serial_port(const String & port_name) {
	if (serial.isDeviceOpen()) {
		serial.closeDevice();
	}

//		char port_name_buf[32];
//#if defined (_WIN32) || defined(_WIN64)
//		sprintf(&port_name_buf[0], "\\\\.\\COM%d", port_id);
//#endif
//#if defined (__linux__) || defined(__APPLE__)
//		sprintf(&port_name_buf[0], "/dev/ttyS%d", port_id);
//#endif

	if (serial.openDevice(port_name.ascii().ptr(), 9600) != 1) {
		ERR_PRINT("Serial lib: could not connect\n");
	}
	return serial.isDeviceOpen();
}

bool Serial::is_serial_connected() {
	return serial.isDeviceOpen();
}

void Serial::disconnect_serial() {
	if (serial.isDeviceOpen()) {
		serial.closeDevice();
	}
}

Serial::Serial() {
}

Serial::~Serial() {
	disconnect_serial();
}
