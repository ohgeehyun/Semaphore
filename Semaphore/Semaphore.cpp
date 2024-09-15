// Semaphore.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
/*
    정리-
	전체적으로 simpleSemaphore 에서  세마포어 핸들러와 스레드가 늘어났다.
	thread_2는 sem1 핸들러에
	thread_3은 sem2 핸들러에
	thread_4은 sem3 핸들러에
	thread_5은 sem4 핸들러에 
	신호를 받고 스레드를 생명주기의 waiting/blocked상태로 들어가서 대기를 하거나 조건이 만족되면 다시 runnable상태를 거처 running상태가된다.

	p.s 개인적인 생각 
	아쉬운점은 최초에 실행될때만 세마포어가 의미있고 사실 한번 병렬로 실행 이후에는 크게 의미가없다. 
    순서상 첫 순회에 thread_5가 실행 된 이후에는 스레드 1 2 3 4 5  가 랜덤으로 실행되는데 보기에만 순차적으로 돌아가는 것 처럼보인다.
	이유는 os의 스레드 스케줄러에의해 1 2 3 4 5 로 돌아가는 것 처럼 보이고 디버깅을위해 디버깅 포인트를 찍고 디버그 시 순서가 박살난다.
	제대로 하기 위해선 thread1과 thread5에 추가적인 조건을 붙히고 최초에 한 싸이클이 돌고나면 sem 핸들러들은 이미 세마포어 카운터에 +1을 해준 상태로 계속도니
	한싸이클을 돌고 난 뒤에는 세마포어 핸들러를 지정해준 의미가없다고 생각한다.

	참조 : https://easycode.tistory.com/26

*/


#include <iostream>
#include <thread>
#include <Windows.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctime>
#include <stdio.h>

// generated Header
#include "header_v1.h" // 구조체를 선언한 헤더 파일 구조체에 int32 배열이 선언되어있지만 크게 의미 있게 사용되지는 않는다. 어떻게 돌아가는지 체크용으로 넣음

// Define
#define CNT 15

// namespace
using namespace std;

HANDLE sem1, sem2, sem3, sem4, sem5; //세마포어 핸들러

void thread_1(MAIN_FORMAT* ts) {
	// local variable 
	int thread_1_count = 0;
	int runningtime = 0;

	clock_t start_time;
	clock_t end_time;

	while (true) {
		start_time = clock();
		this_thread::sleep_for(chrono::milliseconds(100)); // Sleep for 100 milliseconds to simulate work
		/*
		Add function performed by the thread
		*/
		end_time = clock();
		runningtime = end_time - start_time;
		printf("%d thread_1 is worked..... Running Time : %d..... \n", thread_1_count, runningtime);
		thread_1_count += 1;
		if (thread_1_count > CNT)
		{
			thread_1_count = 0;
		}
		else {}
		ReleaseSemaphore(sem1, 1, NULL);
	}
}

void thread_2(MAIN_FORMAT* ts) {
	int thread_2_count = 0;
	int runningtime = 0;
	clock_t start_time;
	clock_t end_time;
	while (TRUE) {
		WaitForSingleObject(sem1, INFINITE);
		start_time = clock();
		this_thread::sleep_for(chrono::milliseconds(10)); // Sleep for 10 milliseconds to simulate work
		/*
		Add function performed by the thread
		*/
		end_time = clock();
		runningtime = end_time - start_time;
		printf("%d thread_2 is worked..... Running Time : %d..... \n", thread_2_count, runningtime);
		thread_2_count += 1;
		if (thread_2_count > CNT)
		{
			thread_2_count = 0;
		}
		else {}
		ReleaseSemaphore(sem2, 1, NULL);
	}
}

void thread_3(MAIN_FORMAT* ts) {
	int thread_3_count = 0;
	int runningtime = 0;
	clock_t start_time;
	clock_t end_time;
	while (TRUE) {
		WaitForSingleObject(sem2, INFINITE);
		start_time = clock();
		this_thread::sleep_for(chrono::milliseconds(10)); // Sleep for 10 milliseconds to simulate work
		/*
		Add function performed by the thread
		*/
		end_time = clock();
		runningtime = end_time - start_time;
		printf("%d thread_3 is worked..... Runnig Time : %d..... \n", thread_3_count, runningtime);
		thread_3_count += 1;
		if (thread_3_count > CNT)
		{
			thread_3_count = 0;
		}
		else {}
		ReleaseSemaphore(sem3, 1, NULL);
	}
}

void thread_4(MAIN_FORMAT* ts) {
	int thread_4_count = 0;
	int runningtime = 0;
	clock_t start_time = 0;
	clock_t end_time = 0;
	while (TRUE) {
		WaitForSingleObject(sem3, INFINITE);
		start_time = clock();
		this_thread::sleep_for(chrono::milliseconds(10)); // Sleep for 10 milliseconds to simulate work
		/*
		Add function performed by the thread
		*/
		end_time = clock();
		runningtime = end_time - start_time;
		printf("%d thread_4 is worked..... Running Time : %d..... \n", thread_4_count, runningtime);

		thread_4_count += 1;
		if (thread_4_count > CNT)
		{
			thread_4_count = 0;
		}
		else {}
		ReleaseSemaphore(sem4, 1, NULL);
	}
}

void thread_5(MAIN_FORMAT* ts) {
	int thread_5_count = 0;
	int runningtime = 0;
	clock_t start_time;
	clock_t end_time;

	while (TRUE) {
		WaitForSingleObject(sem4, INFINITE);
		start_time = clock();
		this_thread::sleep_for(chrono::milliseconds(10)); // Sleep for 10 milliseconds to simulate work
		/*
		Add function performed by the thread
		*/
		end_time = clock();
		runningtime = end_time - start_time;
		printf("%d thread_5 is worked..... Running Time : %d..... \n", thread_5_count, runningtime);
		thread_5_count += 1;

		if (thread_5_count > CNT)
		{
			thread_5_count = 0;
		}
		else {}
	}
}

int main() {
	// Initialize the semaphores
	sem1 = CreateSemaphore(NULL, 0, 16, NULL); //(기본보안 속성(자식 프로세스 상속 등에 사용), 세마포어 초기접근 가능한 스레드 수, 최대 접근 가능한 스레드 수, 세마포터의 이름 지정하는 문자열 포인터)
	sem2 = CreateSemaphore(NULL, 0, 16, NULL);
	sem3 = CreateSemaphore(NULL, 0, 16, NULL);
	sem4 = CreateSemaphore(NULL, 0, 16, NULL);

	// declare structure
	MAIN_FORMAT main_data; //각 스레드별 구조체 생성
	memset(&main_data, 0, sizeof(main_data)); //메모리에 0으로 할당

	// Create the threads
	thread t1(thread_1, &main_data); //스레드 생성 스레드 생명주기의 new -> runnable->running상태까지 
	thread t2(thread_2, &main_data);
	thread t3(thread_3, &main_data);
	thread t4(thread_4, &main_data);
	thread t5(thread_5, &main_data);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	CloseHandle(sem1);
	CloseHandle(sem2);
	CloseHandle(sem3);
	CloseHandle(sem4);
	CloseHandle(sem5);

	return 0;
}
