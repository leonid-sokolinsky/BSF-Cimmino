/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Cimmino
Module: Problem-bsfTypes.h (Predefined Problem-depended BSF Types)
Prefix: PT_bsf
Author: Leonid B. Sokolinsky
This source code is a part of BSF Skeleton (https://github.com/leonid-sokolinsky/BSF-skeleton)
==============================================================================*/
#pragma once
#include "Problem-Types.h"		// Problem Types 

//=========================== BSF Types =========================
struct PT_bsf_parameter_T {			
	PT_vector_T x;	// Current approximation
};
struct PT_bsf_mapElem_T {		
	PT_vector_T a;		// Left side of the equation a[0]*x_1+...+a[n-1]*x_n = b
	PT_float_T b;	// Right side of the equation a[0]*x_1+...+a[n-1]*x_n = b
	PT_float_T normSquare; // normSquare = a[0]*a[0]+...+a[n-1]*a[n-1]
};
struct PT_bsf_reduceElem_T {		
	PT_vector_T projection;		// ProjectionVector of point onto hyperplane		
};

struct PT_bsf_reduceElem_T_1 {				
	// optional filling
};

struct PT_bsf_reduceElem_T_2 {
	// optional filling
};

struct PT_bsf_reduceElem_T_3 {
	// optional filling
};