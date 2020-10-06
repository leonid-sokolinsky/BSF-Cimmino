/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Cimmino
Module: Problem-Parameters.h (Problem Parameters)
Prefix: PP
Author: Leonid B. Sokolinsky
This source code is a part of BSF Skeleton (https://github.com/leonid-sokolinsky/BSF-skeleton)
==============================================================================*/

//=========================== Problem Parameters =========================
#define PP_N 4					// Dimension of space = Number of equations
#define PP_INIT_POINT	100		// Value of all coordinates of initial approximation
#define PP_LAMBDA		1		// Relaxation factor
#define PP_MAX_ITER_COUNT 1000
#define PP_EPS 1E-5				// Precision

//-------------------------- Outpoot Parameters ---------------------------
#define PP_OUTPUT_LIMIT	11	// Number of Elements to output

//-------------------------- Macroses ---------------------------
#define PP_MIN(x,y) (x<y?x:y)