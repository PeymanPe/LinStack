#ifndef LINIF_H
#define LINIF_H

//#include <stdint.h>
#include "LinIf_Types.h"
#include "Std_Types.h"
#ifdef __cplusplus
extern "C" {
#endif

	typedef uint8 LinIf_SchHandleType;


	//
	//enum frame_t {
	//	UNCONDITIONAL = 0,
	//	SPORADIC,
	//	EVENT_TRIGGERED,
	//	DIAGNOSTIC
	//};
	//
	//
	//enum publish_lin_t {
	//	PUB_FALSE,
	//	PUB_TRUE,
	//	NOT_CONFIGURED_PUB
	//};
	//
	//enum subscriber_lin_t {
	//	SUB_TRUE,
	//	SUB_FALSE,
	//	NOT_CONFIGURED_SUB
	//};
	//
	//typedef struct schedule_table_t* schedule_table_p;
	//
	//struct linif_frame_t {
	//	int							id;
	//	int							frame_index;
	//	enum publish_lin_t			is_publisher;
	//	enum subscriber_lin_t		is_subscriber;
	//	enum frame_t				frametype;
	//	schedule_table_p			collision_resolver;
	//
	//};
	//
	//
	//
	//struct schedule_table_row_t {
	//	struct linif_frame_t	frame;
	//	int						delay;
	//};
	//
	//enum schedule_type {
	//	NORMAL_SCHEDULE,
	//	CONFIGURATION_SCHEDULE,
	//	MRF_SCHEDULE,
	//	SRF_SCHEDULE,
	//	COLLISION_RESOLVER_SCHEDULE
	//};
	//
	//struct schedule_table_t {
	//	struct schedule_table_row_t* schedule_table_row;
	//	int						     row_count; //it shows the number of frames
	//	enum schedule_type			 schedule_table_type;
	//
	//};
	//
	//struct schedule_table_config {
	//
	//	struct schedule_table_t* schedul_table;
	//	int						 table_count;
	//
	//};
	//
	//typedef struct schedule_table_config tablelist;

	enum LinIfFrameType_E {
		UNCONDITIONAL,
		MRF,
		SRF,
		EVENT_TRIGGERED,
		SPORADIC,
		ASSIGN,
		UNASSIGN,
		ASSIGN_NAD,
		FREE,
		SAVE_CONGIGURATION,
		ASSIGN_FRAME_id_RAMGE

	};

	enum LinIfChecksumType_E {
		CLASSIC,
		ENHANCED
	};


	typedef struct {
		uint8						LinIfFrameid;
		uint8						LinIfFrameIndex;
		enum LinIfFrameType_E		LinIfFrameType;
		enum LinIfChecksumType_E	LinIfChecksumType;
		//LinIfPduDirection
	}LinIfFrame_S;





	typedef struct {
		uint8					LinIfEntryIndex;
		uint8					LinIfDelay;
		//LinIfFrame_S*					LinIfFrameRef;
		//LinIfScheduleTable_S* LinIfCollisionResolvingRef; //Reference to the schedule table, which resolves the collision.

	}LinIfEntry_S;



	enum LinIfRunMode_E {
		RUN_CONTINUOUS,
		RUN_ONCE
	};

	enum LinIfResumePosition_E {
		START_FROM_BEGINNING,
		CONTINUE_AT_IT_POINT
	};


	typedef struct {
		uint8_t					LinIfScheduleTableIndex;
		enum LinIfRunMode_E				   LinIfRunMode;
		enum LinIfResumePosition_E	LinIfResumePosition;
		LinIfEntry_S						 LinIfEntry;

	}LinIfScheduleTable_S;





	enum node_type_E {
		LinIfMaster,
		LinIfSlave

	};



	typedef struct {
		enum node_type_E	nodeType;
		uint8_t			 LinIfJitter;

	}LinIFNode_S;


	enum LinIfUL_E{
		CDD,	//Complex Driver
		LIN_SM //LIN State Manager
	};


	typedef struct {

		LinChannel_S*					LinIfChannelRef;
		
		//LinIfTransceiverDrvConfig;
		uint16							LinIfMaxFrameCnt;
		boolean							LinIfScheduleChangeNextTimeBase;
		//LinIfComMNetworkHandleRef
		//LinIfCddRef ECUC_LinIf_00637
		LinIFNode_S						LinIfNodeType;
		float32							LinIfBusIdleTimeoutPeriod; //check type later
		float32							LinIfMainFunctionPeriod;
		enum LinIfUL_E					LinIfScheduleRequestConfirmationUL; //ECUC_LinIf_00600
		enum LinIfUL_E					LinIfGotoSleepConfirmationUL; //ECUC_LinIf_00601
		enum LinIfUL_E					LinIfWakeupConfirmationUL;	//ECUC_LinIf_00602
		enum LinIfUL_E					LinIfGotoSleepIndicationUL; //ECUC_LinIf_00652
		LinIfScheduleTable_S*			LinIfScheduleTable;
		LinIfFrame_S					LinIfFrame;

	}LinIfChannel_S;


	typedef struct {
		LinIfChannel_S* LinIfChannel;

	}LinIfGlobalConfig_S;

	void LinIf_Init(const void* ConfigPtr);
	void LinIf_MainFunction(void);
	Std_ReturnType LinIf_ScheduleRequest(NetworkHandleType Channel, LinIf_SchHandleType Schedule);

#ifdef __cplusplus
}
#endif

#endif /* LINIF */