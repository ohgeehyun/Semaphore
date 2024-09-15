#pragma once
#include <iostream>

// Define
#define OUT 16

typedef struct _THREAD1_FORMAT {

	int32_t g_thrad1_Ispare01[OUT]; // int32 32비트짜리(4바이트) 정수형 배열선언 왜 쓰는지 찾아보니까 어떤플랫폼이든 동일한 bit수를 사용한 자료형을  사용하기위해(이식성)
									// 임베디드나 메모리 사용 관리를 잘해야하는 쪽에서 사용해서 컨트롤하는 경우가 많다.

}THREAD1_FORMAT;

typedef struct _THREAD2_FORMAT {

	int32_t g_thrad2_Ispare01[OUT];

}THREAD2_FORMAT;

typedef struct _THREAD3_FORMAT {

	int32_t g_thrad3_Ispare01[OUT];

}THREAD3_FORMAT;

typedef struct _THREAD4_FORMAT {

	int32_t g_thrad4_Ispare01[OUT];

}THREAD4_FORMAT;

typedef struct _THREAD5_FORMAT {

	int32_t g_thrad5_Ispare01[OUT];

}THREAD5_FORMAT;

typedef struct _MAIN_FORMAT {
	THREAD1_FORMAT thread1_format;
	THREAD2_FORMAT thread2_format;
	THREAD3_FORMAT thread3_format;
	THREAD4_FORMAT thread4_format;
	THREAD5_FORMAT thread5_format;
}MAIN_FORMAT;

#pragma once
