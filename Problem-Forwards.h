/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Cimmino
Module: Problem-bsf-Forwards.h (Problem Function Forwards)
Author: Leonid B. Sokolinsky 
This source code is a part of BSF Skeleton (https://github.com/leonid-sokolinsky/BSF-skeleton)
==============================================================================*/
#include "Problem-bsfTypes.h"	// Predefined Problem Parameters
#include "Problem-Types.h"		// Problem Types

static PT_floatPoint_T	DotProduct(PT_point_T x, PT_point_T y);
static bool		StopCond(PT_bsf_parameter_T* parameter); // Calculates the stop condition
static PT_floatPoint_T	NormSquare(PT_point_T x);