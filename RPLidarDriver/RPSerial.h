#pragma once

#include "Arduino.h"
#include "SoftwareSerial.h"

class RPSerial
{
public:
	RPSerial(HardwareSerial * serialobj);
	RPSerial(SoftwareSerial * serialobj);
	~RPSerial();
	void begin(int baud);
	int read();
	void write(uint8_t * data, int s_byte);
	void end();

protected:
	int serialtype;
	HardwareSerial * hw_serial;
	SoftwareSerial * sw_serial;
};