
#include "../includes/LinIf.h"
#define NULL_SCHEDULE 0x00

#define CHANNEL_COUNT	0X01


void LinIf_Init(const void* ConfigPtr)
{

}


void LinIf_MainFunction(void)
{
	int8_t channel_index;
	for (channel_index = 0; channel_index < CHANNEL_COUNT; channel_index++)
	{
		//
	}

}

Std_ReturnType LinIf_ScheduleRequest(NetworkHandleType		Channel, 
									LinIf_SchHandleType		Schedule)
{
	return (Std_ReturnType)E_OK;
}
