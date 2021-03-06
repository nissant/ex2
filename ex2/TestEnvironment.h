/*
Authors			- Eli Slavutsky (308882992) & Nisan Tagar (302344031)
Project Name	- Ex2
Description		- This program impelments an application testing environment. Tests are run in parallel using threads and results are
					written in text output file once all threads have terminated.
				- This module handles all test thread related routines
*/

#include <windows.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <tchar.h>


#ifndef TESTENVIRONMENT_H
#define TESTENVIRONMENT_H

// Includes --------------------------------------------------------------------


// Constants -------------------------------------------------------------------
#define MAX_LINE_LEN 100
#define MAX_RESULTS_LINE_LEN 15
#define BRUTAL_TERMINATION_CODE 0x55

typedef struct test_struct{
	HANDLE test_thread_handle;						// Test thread data
	DWORD test_thread_id;							// Test thread data
	char app_cmd_line[MAX_LINE_LEN];				// String of size MAX_LINE_LEN holding app full path with args
	char app_exp_results_path[MAX_LINE_LEN];		// String of size MAX_LINE_LEN holding app expected resuts full path
	char app_test_results[MAX_RESULTS_LINE_LEN];	// String of size MAX_RESULTS_LINE_LEN holding test results: 
													// "Succeeded", "Timed Out", "Failed", "Crashed -xx", "NULL" for test not finished
	struct test_struct *next_test;
} test_app;

// Function Declarations -------------------------------------------------------

int runTestThreads(test_app *test_list_ptr, HANDLE *thread_handles);
int createAppTestList(char *tst_file_path, test_app **lst_ptr, int *test_counter);
test_app *MakeTestFromLine(char *line);
void AddTestToList(test_app **lst_ptr, test_app *new_test);
int checkThreads(test_app *test_list_ptr);
int createResultsFile(char *report_file_path,test_app *lst_ptr);
void ClearTestList(test_app *lst_ptr);
BOOL CreateThreadSimple(LPTHREAD_START_ROUTINE p_start_routine, test_app *tst_ptr, LPDWORD p_thread_id, HANDLE *thread_handle_ptr);
char *trimwhitespace(char *str);

#endif // !APPTEST_H_INCLUDE






