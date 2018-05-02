/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: Using BSF Skeleton for Cimmino Algorithm Implementation
Module: Problem-Data.h (Problem Data)
Author: Leonid B. Sokolinsky
Creation Date: 09.04.2017
==============================================================================*/
#pragma once
#include "Problem-Parameters.h"		// Problem Parameters 

//========================== Problem variables ====================================

//========================== Problem structures ====================================
static PP_FLOAT_POINT_TYPE PD_A[PP_M][PP_N];	// Coefficients of inequations
static PP_FLOAT_POINT_TYPE PD_b[PP_M];		// Vector of right parts
static PP_FLOAT_POINT_TYPE PD_normSquare_a[PP_M];