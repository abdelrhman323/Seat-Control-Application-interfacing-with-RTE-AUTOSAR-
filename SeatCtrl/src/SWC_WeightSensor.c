/**
 *
 * \file SWC_WeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_WeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/27/2022 02:48 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_WeightSensor.h"


/**
 *
 * Runnable RE_WeightSensor_GetWeight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppWeightSensor_Opr_GetWeight
 *
 */

void RE_WeightSensor_GetWeight (Impl_SensorWeightType* Arg_Weight)
{
	Impl_IoWeightSensorReadingType Arg_weight;

	(void)Rte_Call_rpIOGetWeight_Opr_IOGet(&Arg_weight);
	
	Arg_Weight = (Impl_SensorWeightType)(Arg_weight/1000);
	
}

