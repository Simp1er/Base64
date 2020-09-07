#include <jni.h>
#include <string>
#include <iostream>
#include "base64.h"
#include "log.h"
using namespace std;
extern "C" JNIEXPORT jstring JNICALL
Java_com_test_base64_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    base64 * test = new base64();
    string dest;

    test->base64Encode(dest, const_cast<char *>(hello.c_str()), hello.length());
    LOGD("%s",dest.c_str());
    string dest1;
    test->base64Decode(dest1, const_cast<char *>(dest.c_str()), dest.length());
    LOGD("%s",dest1.c_str());
    return env->NewStringUTF(hello.c_str());
}
