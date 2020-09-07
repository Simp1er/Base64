//
// Created by Simp1er on 2020-09-07.
//
#include <android/log.h>
#define DEBUG
#ifdef DEBUG
#define LOG_TAG "ceshi"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#else
#define  LOGI(...)   ((void)0)
#endif

