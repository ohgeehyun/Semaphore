#pragma once
#include <iostream>

// Define
#define OUT 16

typedef struct _THREAD1_FORMAT {

	int32_t g_thrad1_Ispare01[OUT]; // int32 32��Ʈ¥��(4����Ʈ) ������ �迭���� �� ������ ã�ƺ��ϱ� ��÷����̵� ������ bit���� ����� �ڷ�����  ����ϱ�����(�̽ļ�)
									// �Ӻ���峪 �޸� ��� ������ ���ؾ��ϴ� �ʿ��� ����ؼ� ��Ʈ���ϴ� ��찡 ����.

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
