/// @copyright gm 2021

#ifndef SERIAL_H
#define SERIAL_H

#include "core/reference.h"

// Serial library
#include <serialib.h>

class Serial : public Reference {
	GDCLASS(Serial, Reference);

	serialib serial;

protected:
	static void _bind_methods();
	void reset();

public:
	void write_char(int);
	int read_char();
	void write_string(const String&);
	String read_string();

	int available();

	// "To specify a COM port number greater than 9, use the following syntax: "\\.\COM10".
	// This syntax works for all port numbers and hardware that allows COM port numbers to be specified."
	// https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea?redirectedfrom=MSDN#communications-resources
	bool connect_to_serial_port(const String& port_name);

	bool is_serial_connected();
	void disconnect_serial();

	Serial();
	~Serial();
};

#endif // SERIAL_H
