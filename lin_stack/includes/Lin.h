#ifndef LIN_H
#define LIN_H
#include "ComStack_Types.h"


#ifdef __cplusplus
extern "C" {
#endif

	enum Lin_Node_Type_E {
		MASTER,
		SLAVE
	};

	typedef struct {
		uint16								LinChannelId;
		enum Lin_Node_Type_E				LinNodeType;
		//LinChannelEcucPartitionRef
		boolean								LinChannelWakeupSupport;
		//LinClockRef;
		uint32								LinChannelBaudRate;
	}LinChannel_S;

	typedef struct {
		LinChannel_S*						LinChannel;
	}LinGlobalConfig_S;

#ifdef __cplusplus
}
#endif

#endif
