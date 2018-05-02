/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: Using BSF Skeleton for Cimmino Algorithm Implementation
Module: Problem-Types.h (BSF Types)
Prefix: PT
Author: Leonid B. Sokolinsky
Creation Date: 09.04.2017
==============================================================================*/
#pragma once						
#include "Problem-Parameters.h"		// Problem Parameters 

//=========================== Problem Types =========================
typedef PP_FLOAT_POINT_TYPE PT_point_T[PP_N];	// Point in n-Dimensional Space

//=========================== BSF Types =========================
struct PT_bsf_data_T {				// Data for workers
	PP_FLOAT_POINT_TYPE approximation[PP_N];		// Current approximation
};

struct PT_bsf_mapElem_T {			// Element of map list
	int inequationNo;
};

struct PT_bsf_reduceElem_T {		// Element of reduce list	
	PP_FLOAT_POINT_TYPE point[PP_N];
};