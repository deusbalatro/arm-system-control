#include "mbed.h"

#define BUTTON_START p5
#define BUTTON_STOP p6
#define SWITCH_GUARD p7
#define SWITCH_TEMP p8
#define BUTTON_SHUT p13

#define LED_READY p9
#define LED_RUNNING p10
#define LED_GUARD p11
#define LED_TEMP p12

// B stands for button, s stands for switch
DigitalIn bstart(BUTTON_START);
DigitalIn bstop(BUTTON_STOP);
DigitalIn sguard(SWITCH_GUARD);
DigitalIn stemp(SWITCH_TEMP);
DigitalIn bshut(BUTTON_SHUT);

DigitalOut ready(LED_READY);
DigitalOut running(LED_RUNNING);
DigitalOut guard_on(LED_GUARD);
DigitalOut temp_high(LED_TEMP);


void Waiting(bool _isStart);
void Running(bool _isStart);
void Pause(bool _isStart);
void Shut(bool _isStart);

int main()
{

	Waiting(false);

}

void Waiting(bool _isStart)
{

	while(_isStart == false)
	{

		if (sguard && !stemp)
		{
				ready = 0;
				running = 0;
				guard_on = 1;
				temp_high = 0;
		}

		if (!sguard && stemp)
		{
				ready = 0;
				running = 0;
				guard_on = 0;
				temp_high = 1;
		}

		if (sguard && stemp)
		{
				ready = 0;
				running = 0;
				guard_on = 1;
				temp_high = 1;
		}

		if (!sguard && !stemp)
		{
				ready = 1;
				running = 0;
				guard_on = 0;
				temp_high = 0;
		}

		wait(0.25);

		if (bstart && (!sguard && !stemp))
		{
			_isStart = true;
			break;
		}
		else
			continue;
	}


	Running(_isStart);

}

void Running(bool _isStart)
{


	while (_isStart == true)
	{
		running = 1;
		guard_on = 0;
		temp_high = 0;

		ready = 0;
		wait(0.25);

		ready = 1;
		wait(0.10);

		if (bstop || stemp || sguard || bshut)
		{
			_isStart = false;
			break;
		}

	}

	bshut ? Shut(_isStart) : Pause(_isStart);

}

void Pause(bool _isStart)
{


	while (_isStart == false)
	{
		ready = 1;
		running = 0;
		temp_high = 0;
		guard_on = 0;

		if(stemp)
		{
			ready = 0;
			running = 0;
			temp_high = 1;
			sguard ? guard_on = 1 : guard_on = 0;
		}
		if (sguard)
		{
				ready = 0;
				running = 0;
				stemp ? temp_high = 1 : temp_high = 0;
				guard_on = 1;
		}
		if (!bstop && !sguard && !stemp)
		{
			_isStart = 1;
			break;
		}

		wait (0.25);
	}

	Running(_isStart);

}

void Shut(bool _isStart)
{
    if (_isStart == false)
        main();
}
