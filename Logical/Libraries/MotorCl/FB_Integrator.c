
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCl.h"
#ifdef __cplusplus
	};
#endif
/* Integrator */
void FB_Integrator(struct FB_Integrator* inst)
{
	inst-> out = inst->old_err + (inst->in)* inst->dt;
	inst->old_err= inst->out;
	
}
