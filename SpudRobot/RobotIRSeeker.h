#ifndef ROBOTIRSEEKER_H
#define ROBOTIRSEEKER_H

#include <Arduino.h>
#include <Wire.h>

	struct InfraredResult{
		byte Direction;
		byte Strength;
	};

	class RobotIRSeeker{

		public:
			static void Initialize();
			static boolean Test();
			static void ReadACRaw(byte* buffer);
			static void ReadDCRaw(byte* buffer);
			static InfraredResult ReadAC();
			static InfraredResult ReadDC();
			static int DirectionAngle(byte Direction);
		private:
			static InfraredResult PopulateValues(byte* buffer);
			static void ReadValues(byte OffsetAddress, byte* buffer);
			static const int Address = 0x10 / 2; //Divide by two as 8bit-I2C address is provided
	};

#endif
