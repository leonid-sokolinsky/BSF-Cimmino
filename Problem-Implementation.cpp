/*==============================================================================
Project: Bulk Synchronous Farm (BSF)
Theme: Using BSF Skeleton for Cimmino Algorithm Implementation
Module: Problem-Implementation.h (Implementation of the Problem)
Prefix: PI
Author: Leonid B. Sokolinsky
Creation Date: 09.04.2017
==============================================================================*/
#include "Problem-Include.h"
#include "Problem-Types.h"			// Problem Types 
#include "Problem-Data.h"			// Problem Data 
#include "Problem-Parameters.h"		// Problem Parameters 
#include "Problem-Forwards.h"		// Function Forwards

using namespace std;
#define MIN(x,y) (x<y?x:y)

void PI_bsf_MapF(PT_bsf_mapElem_T* mapElem, PT_bsf_reduceElem_T* reduceElem, PT_bsf_data_T* data, int* success) {
	PI_Semiprojection(data->approximation, mapElem->inequationNo, reduceElem->point);
	//*debug*/cout << PD_bsf_rank << ": PI_bsf_MapF: reduceElem->point = ";
	//*debug*/for (int j = 0; j < PP_N; j++) cout << reduceElem->point[j] << "\t"; cout << endl;
};

void PI_bsf_ReduceF(PT_bsf_reduceElem_T* x, PT_bsf_reduceElem_T* y, PT_bsf_reduceElem_T* z) { // z = x + y
	for (int j = 0; j < PP_N; j++)
		z->point[j] = x->point[j] + y->point[j];
};

void PI_bsf_ProcessResults(bool* exit, PT_bsf_reduceElem_T* reduceResult, int count, PT_bsf_data_T* data) {
	static int counter = 0;	// Iteration Counter
	counter++;
	if (counter < PP_ITER_COUNT)
		*exit = false;
	else
		*exit = true;
	
	for (int j = 0; j < PP_N; j++)
		data->approximation[j] += (PP_FLOAT_POINT_TYPE) PP_LAMBDA*reduceResult->point[j] / count;
};

void PI_bsf_CopyData(PT_bsf_data_T* dataIn, PT_bsf_data_T* dataOut) {
	for (int j = 0; j < PP_N; j++)
		dataOut->approximation[j] = dataIn->approximation[j];
};

void PI_bsf_Init(PT_bsf_data_T* data) {

	for (int j = 0; j < PP_N; j++) // Generating coordinates of initial appriximation
		data->approximation[j] = 2 * PP_SF;

	for (int j = 0; j < PP_N; j++) { // Generating Matrix À (including -x_j<=0)
		PD_A[j][j] = 1;
		PD_A[PP_N][j] = 1;
		PD_A[PP_N + 1][j] = -1;
		PD_A[j + PP_N + 2][j] = -1;
	};

	for (int i = 0; i < PP_N; i++) // Generating column b (including -x_j<=0)
		PD_b[i] = PP_SF;
	PD_b[PP_N] = PP_SF*(PP_N - 1) + PP_SF / 2;
	PD_b[PP_N + 1] = -PP_SF / 2;
	for (int i = PP_N + 2; i < 2 * PP_N + 2; i++)
		PD_b[i] = 0;

	for (int i = 0; i < PP_M; i++) // Calculating column of norm squares for rows of matrix A
		PD_normSquare_a[i] = PI_NormSquare(PD_A[i]);
};

void PI_bsf_AssignListSize(int* listSize) {
	*listSize = PP_M;
};

void PI_bsf_AssignMapList(PT_bsf_mapElem_T *mapList, int listSize) {
	for (int j = 0; j < listSize; j++) // First inequation has number 0
		mapList[j].inequationNo = j;
};

void PI_bsf_ProblemOutput(PT_bsf_reduceElem_T* reduceResult, int count, PT_bsf_data_T data,
	int iterCount, double t, double t_L, double t_s, double t_r, double t_w, double t_A_w, double t_A_m, double t_p) {// Output Function

	cout << "---------------------" << endl;/**/
	cout << "Iteration count = " << iterCount << endl;
	cout << "t_L = " << t_L << "\tt_s = " << t_s << "\tt_r = " << t_r << "\tt_w = " << t_w << "\tt_A_w = " << t_A_w << "\tt_A_m = " << t_A_m << "\tt_p = " << t_p << endl;
	cout << "Runtime = " << t << endl;
	cout << "Solution: ";
	for (int j = 0; j < MIN(4,PP_N); j++)
		cout << data.approximation[j] << "\t";
	cout << endl << "---------------------" << endl;
};

void PI_bsf_IterOutput(PT_bsf_reduceElem_T* reduceResult, int count, PT_bsf_data_T data,
	int iterCount, double elapsedTime) {

/*	cout << " " << iterCount << "\tApproximation:\t";
	for (int j = 0; j < PP_N; j++)
	cout << data.approximation[j] << "\t";
	cout << endl;
	cout  << "Elapsed time: " << elapsedTime << endl;/**/
};

void PI_bsf_ParametersOutput(int numOfWorkers, PT_bsf_data_T data) {
	cout << "----------- Cimmino Algorithm ----------" << endl;
	cout << "Number of workers: " << numOfWorkers << endl;
	cout << "n = " << PP_N << endl;
	cout << "m = " << PP_M << endl;
	cout << "Lehgth of float point type: " << sizeof(PP_FLOAT_POINT_TYPE) << endl;
	cout << "Initial approximation:\t";
	for (int j = 0; j < MIN(4,PP_N); j++)
		cout << data.approximation[j] << "\t";
	cout << endl;/**/
};

static void PI_Semiprojection(PT_point_T x, int hyperplaneNo, PT_point_T projection){
	PP_FLOAT_POINT_TYPE factor = (PD_b[hyperplaneNo] - PI_DotProduct(x, PD_A[hyperplaneNo])) / PD_normSquare_a[hyperplaneNo];
	for (int j = 0; j < PP_N; j++)
		projection[j] = factor*PD_A[hyperplaneNo][j];
	//*debug*/cout << PD_bsf_rank << ": PI_Semiprojection: projection = ";
	//*debug*/for (int j = 0; j < PP_N; j++) cout << projection[j] << "\t"; cout << endl;
};

static PP_FLOAT_POINT_TYPE PI_DotProduct(PT_point_T x, PT_point_T y) {
	PP_FLOAT_POINT_TYPE res = 0;
	for (int j = 0; j < PP_N; j++)
		res += x[j] * y[j];
	return res;
};

static PP_FLOAT_POINT_TYPE PI_NormSquare(PT_point_T x) {
	PP_FLOAT_POINT_TYPE res = 0;
	for (int j = 0; j < PP_N; j++)
		res += x[j] * x[j];
	return res;
};
