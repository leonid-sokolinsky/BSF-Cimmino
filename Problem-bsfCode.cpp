/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: BSF Cimmino
Module: Problem-bsfCode.cpp (Problem-dependent Code)
Prefix: PC
Author: Leonid B. Sokolinsky
This source code is a part of BSF Skeleton (https://github.com/leonid-sokolinsky/BSF-skeleton)
==============================================================================*/
#include "Problem-Data.h"			// Problem Types 
#include "Problem-Forwards.h"		// Problem Function Forwards
#include "Problem-bsfParameters.h"	// BSF-skeleton parameters
#include "BSF-SkeletonVariables.h"	// Skeleton Variables
using namespace std;

//----------------------- Predefined problem-dependent functions -----------------
void PC_bsf_Init(bool* success) { 
}; 

void PC_bsf_SetListSize(int* listSize) { 
	*listSize = PP_N;
};

void PC_bsf_CopyParameter(PT_bsf_parameter_T parameterIn, PT_bsf_parameter_T* parameterOutP) {
	for (int i = 0; i < PP_N; i++)
		parameterOutP->x[i] = parameterIn.x[i];
};

void PC_bsf_MapF(PT_bsf_mapElem_T* mapElem, PT_bsf_reduceElem_T* reduceElem, int* success) {
	PT_floatPoint_T factor;

	factor = (mapElem->b - DotProduct(BSF_sv_parameter.x, mapElem->a)) / mapElem->normSquare;
	for (int j = 0; j < PP_N; j++)
		reduceElem->projection[j] = factor * mapElem->a[j];
};

void PC_bsf_MapF_1(PT_bsf_mapElem_T* mapElem, PT_bsf_reduceElem_T_1* reduceElem, int* success) {
	// Optional filling. Do not delete!
};

void PC_bsf_MapF_2(PT_bsf_mapElem_T* mapElem, PT_bsf_reduceElem_T_2* reduceElem, int* success) {
	// Optional filling. Do not delete!
};

void PC_bsf_MapF_3(PT_bsf_mapElem_T* mapElem, PT_bsf_reduceElem_T_3* reduceElem, int* success) {
	// Optional filling. Do not delete!
};

void PC_bsf_ReduceF(PT_bsf_reduceElem_T* x, PT_bsf_reduceElem_T* y, PT_bsf_reduceElem_T* z) { // z = x (+) y
	for (int j = 0; j < PP_N; j++)
		z->projection[j] = x->projection[j] + y->projection[j];
};

void PC_bsf_ReduceF_1(PT_bsf_reduceElem_T_1* x, PT_bsf_reduceElem_T_1* y, PT_bsf_reduceElem_T_1* z) {
	// Optional filling. Do not delete!
};

void PC_bsf_ReduceF_2(PT_bsf_reduceElem_T_2* x, PT_bsf_reduceElem_T_2* y, PT_bsf_reduceElem_T_2* z) {
	// Optional filling. Do not delete!
};

void PC_bsf_ReduceF_3(PT_bsf_reduceElem_T_3* x, PT_bsf_reduceElem_T_3* y, PT_bsf_reduceElem_T_3* z) {
	// Optional filling. Do not delete!
};

void PC_bsf_ProcessResults(
	PT_bsf_reduceElem_T* reduceResult,
	int reduceCounter, 
	PT_bsf_parameter_T* parameter, 
	int* newJobCas,
	bool* exit 
) {
	for (int j = 0; j < PP_N; j++) {
		PD_prev_x[j] = parameter->x[j];
		parameter->x[j] += PP_LAMBDA * reduceResult->projection[j] / PP_N;
	};

	if (StopCond(parameter))
		*exit = true;
	else
		*exit = false;
};

void PC_bsf_ProcessResults_1(
	PT_bsf_reduceElem_T_1* reduceResult,
	int reduceCounter, 
	PT_bsf_parameter_T* parameter, 
	int* nextJob,
	bool* exit 
) {
	// Do not use.
};

void PC_bsf_ProcessResults_2(
	PT_bsf_reduceElem_T_2* reduceResult,
	int reduceCounter, 
	PT_bsf_parameter_T* parameter, 
	int* nextJob,
	bool* exit 
	) {
	// Do not use.
};

void PC_bsf_ProcessResults_3(
	PT_bsf_reduceElem_T_3* reduceResult,
	int reduceCounter, 
	PT_bsf_parameter_T* parameter, 
	int* nextJob,
	bool* exit 
	) {
	// Do not use.
};

void PC_bsf_ParametersOutput(PT_bsf_parameter_T parameter) {
	cout << "=================================================== BSF Cimmino ====================================================" << endl;
	cout << "Number of Workers: " << BSF_sv_numOfWorkers << endl;
#ifdef PP_BSF_OMP
#ifdef PP_BSF_NUM_THREADS
	cout << "Number of Threads: " << PP_BSF_NUM_THREADS << endl;
#else
	cout << "Number of Threads: " << omp_get_num_procs() << endl;
#endif // PP_BSF_NUM_THREADS
#else
	cout << "OpenMP is turned off!" << endl;
#endif // PP_BSF_OMP

	cout << "Dimension: N = " << PP_N << endl;
	cout << "Eps_Square = " << PP_EPS << endl;
	cout << "Initial x: "; for (int j = 0; j < PP_MIN(PP_OUTPUT_LIMIT, PP_N); j++) cout << setw(7) << parameter.x[j]; cout << (PP_OUTPUT_LIMIT < PP_N ? "..." : "") << endl;
	cout << "-------------------------------------------" << endl;
}

void PC_bsf_IterOutput(PT_bsf_reduceElem_T* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double elapsedTime, int jobCase) {
	cout << "------------------ " << BSF_sv_iterCounter << " ------------------" << endl;
	cout << "Approximation:\t\t"; for (int j = 0; j < PP_MIN(PP_OUTPUT_LIMIT, PP_N); j++) cout << setw(12) << parameter.x[j]; 
	cout << (PP_OUTPUT_LIMIT < PP_N ? "..." : "") << endl;/**/
}

void PC_bsf_IterOutput_1(PT_bsf_reduceElem_T_1* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double elapsedTime, int jobCase) {
	cout << "------------------ " << BSF_sv_iterCounter << " ------------------" << endl;
	// Optional filling. Do not delete!

}

void PC_bsf_IterOutput_2(PT_bsf_reduceElem_T_2* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double elapsedTime, int jobCase) {
	cout << "------------------ " << BSF_sv_iterCounter << " ------------------" << endl;
	// Optional filling. Do not delete!

}

void PC_bsf_IterOutput_3(PT_bsf_reduceElem_T_3* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double elapsedTime, int jobCase) {
	cout << "------------------ " << BSF_sv_iterCounter << " ------------------" << endl;
	// Optional filling. Do not delete!

}

void PC_bsf_ProblemOutput(PT_bsf_reduceElem_T* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double t) {
	cout << "=============================================" << endl;
	cout << "Time: " << t << endl;
	cout << "Iterations: " << BSF_sv_iterCounter << endl;
	cout << "Solution: "; for (int j = 0; j < PP_MIN(PP_OUTPUT_LIMIT, PP_N); j++) cout << setw(12) << parameter.x[j]; 
	cout << (PP_OUTPUT_LIMIT < PP_N ? "..." : "") << endl;
}

void PC_bsf_ProblemOutput_1(PT_bsf_reduceElem_T_1* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double t) {
	// Optional filling. Do not delete!
}

void PC_bsf_ProblemOutput_2(PT_bsf_reduceElem_T_2* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double t) {
	// Optional filling. Do not delete!
};

void PC_bsf_ProblemOutput_3(PT_bsf_reduceElem_T_3* reduceResult, int reduceCounter, PT_bsf_parameter_T parameter,
	double t) {
	// Optional filling. Do not delete!
}

void PC_bsf_SetInitParameter(PT_bsf_parameter_T* parameter) {
	for (int i = 0; i < PP_N; i++) // Generating coordinates of initial appriximation
		parameter->x[i] = PP_INIT_POINT;
}

void PC_bsf_SetMapSubList(PT_bsf_mapElem_T* sublist, int sublistLength, int offset) {
	for (int i = 0; i < sublistLength; i++) {
		for (int j = 0; j < offset + i; j++)
			sublist[i].a[j] = 1;
		sublist[i].a[offset + i] = (PT_floatPoint_T)((offset + i) * 2);
		for (int j = offset + i + 1; j < PP_N; j++)
			sublist[i].a[j] = 0;
		sublist[i].b = (PT_floatPoint_T)(3 * (offset + i));
		if (offset == 0) {
			sublist[0].a[0] = 1;
			sublist[0].b = 1;
		}
		sublist[i].normSquare = NormSquare(sublist[i].a);
	}
}

//----------------------- Assigning Values to BSF-skeleton Variables (Do not modify!) -----------------------
void PC_bsfAssignAddressOffset(int value) { BSF_sv_addressOffset = value; }
void PC_bsfAssignIterCounter(int value) { BSF_sv_iterCounter = value; }
void PC_bsfAssignJobCase(int value) { BSF_sv_jobCase = value; }
void PC_bsfAssignMpiRank(int value) { BSF_sv_mpiRank = value; }
void PC_bsfAssignNumberInSublist(int value) { BSF_sv_numberInSublist = value; }
void PC_bsfAssignNumOfWorkers(int value) { BSF_sv_numOfWorkers = value; }
void PC_bsfAssignParameter(PT_bsf_parameter_T parameter) { PC_bsf_CopyParameter(parameter, &BSF_sv_parameter); }
void PC_bsfAssignSublistLength(int value) { BSF_sv_sublistLength = value; }

//----------------------------- User functions -----------------------------
static bool StopCond(PT_bsf_parameter_T* parameter) {// Calculates the stop condition
	PT_point_T difference; // Difference between current and previous approximations

#ifdef PP_MAX_ITER_COUNT
	if (BSF_sv_iterCounter > PP_MAX_ITER_COUNT) {
		cout << "Acceptable maximum number of iterations is exceeded: PP_MAX_ITER_COUNT = " << PP_MAX_ITER_COUNT << endl;
		return true;
	};
#endif // PP_MAX_ITER_COUNT

	for (int j = 0; j < PP_N; j++)
		difference[j] = PD_prev_x[j] - parameter->x[j];
	if (sqrt(NormSquare(difference)) < PP_EPS)
		return true;
	else
		return false;
}

static PT_floatPoint_T DotProduct(PT_point_T x, PT_point_T y) {
	PT_floatPoint_T sum = 0;
	for (int j = 0; j < PP_N; j++)
		sum += x[j] * y[j];
	return sum;
};

static PT_floatPoint_T NormSquare(PT_point_T x) {
	PT_floatPoint_T sum = 0;
	for (int j = 0; j < PP_N; j++)
		sum += x[j] * x[j];
	return sum;
};
