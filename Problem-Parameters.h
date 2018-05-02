/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: Using BSF Skeleton for Cimmino Algorithm Implementation
Module: Problem-Parameters.h (Problem Parameters)
Prefix: PP
Author: Leonid B. Sokolinsky
Creation Date: 09.04.2017
==============================================================================*/
#pragma once
/* ========================= Compilation Modes ======================== */
//#define NDEBUG

#define PP_FLOAT_POINT_TYPE double

//=========================== Problem Parameters =========================
#define PP_N 10			// Dimension of space
#define PP_SF	200			// Scale factor
#define PP_M (2*PP_N+2)		// Number of inequations

#define PP_ITER_COUNT	100
#define PP_LAMBDA		1.9	// Relaxation factor