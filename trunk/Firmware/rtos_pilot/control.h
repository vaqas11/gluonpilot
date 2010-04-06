#ifndef CONTROL_H
#define CONTROL_H

#include "pid.h"


enum MixTypes { AILERON = 0, DELTA_PLUS = 1, DELTA_MIN = 2, QUADROCOPTER  = 3};

enum FlightModes { MANUAL = 0, STABILIZED = 1, AUTOPILOT = 2, LOITER = 3, RETURN = 4};

struct ControlState
{
	enum FlightModes flight_mode;
	double desired_roll;
	double desired_pitch;
	double desired_height;
};

extern struct ControlState control_state;

/*!
 *   This struct assigns channel input (from the rc transmitter - see ppm_in or pwm_in) to a function.
 */
struct ControlConfig
{
	int channel_motor;
	int channel_ap;
	int channel_pitch;
	int channel_roll;
	int channel_yaw;
	
	int channel_neutral[8];
	int servo_neutral[6];
	int servo_max[6];
	int servo_min[6];
	
	unsigned int reverse_servo1 : 1;
	unsigned int reverse_servo2 : 1;
	unsigned int reverse_servo3 : 1;
	unsigned int reverse_servo4 : 1;
	unsigned int reverse_servo5 : 1;
	unsigned int reverse_servo6 : 1;
	
	unsigned int manual_trim : 1;
	unsigned int use_pwm : 1;

	enum MixTypes servo_mix;	
	float max_roll;
	float max_pitch;
	
	//! Pid structs to control the stabilization
	struct pid pid_roll2aileron;
    struct pid pid_pitch2elevator;
    struct pid pid_heading2roll;
};	


void control_init();

void control_task( void *pvParameters );


#endif // CONTROL_H