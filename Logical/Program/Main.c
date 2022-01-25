
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	REAL t;
	
	Speed=200;
	t=0;
	
	fb_regulator.dt =0.002;
	fb_regulator.e=10;
	fb_regulator.ki=0.16;
	fb_regulator.kp=0.0064;
	fb_regulator.max_abs_value=300;
	
	fb_motor.dt=0.002;
	fb_motor.Tm=0.04;
	fb_motor.ke = (fb_regulator.ki*3*fb_regulator.dt);
	

	fb_motor2.dt=0.002;
	fb_motor2.Tm=0.04;
	fb_motor2.ke = (fb_regulator.ki*3*fb_regulator.dt);
}

void _CYCLIC ProgramCyclic(void)
{
	
	

	if (enable == 1)
	{
		Speed = 200;
	}
	else 
	{
		Speed = 0;
	}
	t=t+0.001;
	fb_regulator.e=Speed-fb_motor.w;
	FB_Regulator(&fb_regulator);
	fb_motor.u=fb_regulator.u;
	FB_Motor(&fb_motor);
	fb_motor2.u = Speed-fb_motor2.w;
	FB_motor2(&fb_motor2);
	
	if((t>=5)&&(t<10))
	{
		enable = 1;
	}
	if ((t>=10)&&(t<15))
	{
		enable = 0;
	}
	if (t>=15)
	{
		enable = 1;
		t = 0;
	}
}

void _EXIT ProgramExit(void)
{

}

