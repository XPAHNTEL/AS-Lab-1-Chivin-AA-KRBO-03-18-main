
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCl.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_motor2(struct FB_motor2* inst)

	{
		REAL variable;

		variable = inst->u/inst->ke;
		variable = variable - inst->w;
		variable = variable * inst->dt/inst->Tm;
		inst->integrator.in = variable;
		inst->integrator.dt = inst->dt;
		FB_Integrator(&inst->integrator);
		variable=inst->integrator.out;
		FB_Integrator(&inst->integrator);
		inst->w=variable;
	
		inst->integrator.in=inst->w * inst->dt;
		FB_Integrator(&inst->integrator);
		inst->phi+=inst->integrator.out;
		FB_Integrator(&inst->integrator);
	}

