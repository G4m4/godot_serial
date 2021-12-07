/// @copyright gm 2021

#ifndef SERIAL_H
#define SERIAL_H

#include "core/reference.h"

// Serial library
#include <serialib.h>

class Serial : public Reference {
	GDCLASS(Serial, Reference);

	serialib serial;
	int port_id;

protected:
	static void _bind_methods();
	void reset();

public:
	void write_char(int);
	int read_char();
	void write_string(const String&);
	String read_string();

	int available();

	bool connect_to_serial_port(int port_id);
	bool is_serial_connected();
	void disconnect_serial();

	Serial();
	~Serial();
};

#endif // SERIAL_H
