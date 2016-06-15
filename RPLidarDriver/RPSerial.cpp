#include "RPSerial.h"

RPSerial::RPSerial(HardwareSerial * serialobj)
{
	hw_serial = serialobj;
	sw_serial = NULL;
}

RPSerial::RPSerial(SoftwareSerial * serialobj)
{
	hw_serial = NULL;
	sw_serial = serialobj;
}

void RPSerial::begin(int baud) {
	if (hw_serial) {
		hw_serial->begin(baud);
	} else {
		sw_serial->begin(baud);
	}
}

int RPSerial::read() {
	if (hw_serial) {
		return hw_serial->read();
	}

	return sw_serial->read();
}

void RPSerial::write(uint8_t * data, int s_byte) {
	if (hw_serial) {
		hw_serial->write(data, s_byte);
	} else {
		sw_serial->write(data, s_byte);
	}
}

void RPSerial::end() {
	if (hw_serial) {
		hw_serial->end();
	} else {
		sw_serial->end();
	}
}