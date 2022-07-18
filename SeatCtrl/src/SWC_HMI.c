/**
 *
 * \file SWC_HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/25/2022 03:21 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HMI.h"


/**
 *
 * Runnable RE_HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_HMI_MainFunction_100ms
 *
 */
static Impl_MultiStateBtnType btnToState(uint8 value)
{
   Impl_MultiStateBtnType  btnState;
   if(value == 1)
   {
     btnState = MULTI_STATE_BTN_MINUS;
   }
   else if(value == 2)
   {
     btnState = MULTI_STATE_BTN_PLUS;
   }
   else
   {
     btnState =  MULTI_STATE_BTN_INIT;		
   }
   return btnState;
}

void RE_HMI_MainFunction (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType DE_HeightBtnState;
	Impl_MultiStateBtnType DE_InclineBtnState;
	Impl_MultiStateBtnType DE_SlideBtnState;
	uint8 DE_Hight;
	uint8 DE_Incline;
	uint8 DE_Slide;

	status = Rte_Read_rpSeatCtrlData_DE_Hight(&DE_Hight);
	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Hight();	
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
	  DE_HeightBtnState = btnToState(DE_Hight);
	  (void)Rte_Write_ppSeatCtrlBtns_DE_HeightBtnState(DE_HeightBtnState);
	}


	status = Rte_Write_ppSeatCtrlBtns_DE_InclineBtnState(DE_InclineBtnState);
	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Incline();	
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
	  DE_InclineBtnState = btnToState(DE_Incline);
	  (void)Rte_Write_ppSeatCtrlBtns_DE_InclineBtnState(DE_InclineBtnState);
	}

	status = Rte_Write_ppSeatCtrlBtns_DE_SlideBtnState(DE_SlideBtnState);
	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Slide();	
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
	  DE_HeightBtnState = btnToState(DE_Slide);
	  (void)Rte_Write_ppSeatCtrlBtns_DE_SlideBtnState(DE_SlideBtnState);
	}
	
}

void RE_HMI_SeatModeChanged (void)
{
	Impl_SeatModeBtnType DE_SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	(void)Rte_Read_rpSeatModeBtn_SeatModeBtn(&DE_SeatModeBtn);
	
	if( DE_SeatModeBtn== SEAT_MODE_BTN_MANUAL)
	{
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
	}
	else if( DE_SeatModeBtn== SEAT_MODE_BTN_AUTO)
	{
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
	}
	else
	{
		/* Keep INIT */
	}

	(void)Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);	
	
}