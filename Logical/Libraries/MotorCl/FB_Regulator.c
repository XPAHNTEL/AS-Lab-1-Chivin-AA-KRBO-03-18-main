
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCl.h"
#ifdef __cplusplus
	};
#endif
/* PID regulator */
void FB_Regulator(struct FB_Regulator* inst)
{
	REAL variable;
	
	variable = inst->e*inst->ki*inst->dt;
	variable += inst->iyOld;
	inst->integrator.in=variable;
	inst->integrator.dt=inst->dt;
	FB_Integrator(&inst->integrator);
	
	
	if(inst->e*inst->kp>inst->max_abs_value)
	{
			
		variable=inst->integrator.out+inst->max_abs_value;
			FB_Integrator(&inst->integrator);
	}
	if(inst->e*inst->kp<inst->max_abs_value)
	{
		variable=inst->integrator.out+inst->e*inst->kp;
			FB_Integrator(&inst->integrator);
	}
	if(variable>inst->max_abs_value)
	{
		inst->u=inst->max_abs_value;
		inst->iyOld=variable-inst->max_abs_value;		
	}
	else
	{
		inst->u=variable;
		inst->iyOld=0;
	}
}
