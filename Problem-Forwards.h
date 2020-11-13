/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Cimmino
Module: Problem-bsf-Forwards.h (Problem Function Forwards)
Author: Leonid B. Sokolinsky 
This source code is a part of BSF Skeleton (https://github.com/leonid-sokolinsky/BSF-skeleton)
==============================================================================*/
#include "Problem-bsfTypes.h"	// Predefined Problem Parameters
#include "Problem-Types.h"		// Problem Types

inline PT_float_T A(int i, int j);		// Matrix A
inline PT_float_T b(int i);				// Column b of right parts
static PT_float_T	DotProduct(PT_vector_T x, PT_vector_T y);
static bool		StopCond(PT_bsf_parameter_T* parameter); // Calculates the stop condition
static PT_float_T	NormSquare(PT_vector_T x);