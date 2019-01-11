#include "native-lib.h"
#include "break_exception.h"

google_breakpad::ExceptionHandler *exceptionHandler;

JNIEXPORT jstring JNICALL
Java_com_example_testbreakpad_BreadpadException_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT void JNICALL
Java_com_example_testbreakpad_BreadpadException_init(JNIEnv *env, jobject instance, jstring path_) {

    const char *path = env->GetStringUTFChars(path_, 0);
    initBreakpad(path, exceptionHandler);
    env->ReleaseStringUTFChars(path_, path);
}


JNIEXPORT void JNICALL
Java_com_example_testbreakpad_BreadpadException_breakSomething(JNIEnv *env, jobject instance) {

    doSomething();

}