//
// Created by xhp on 18-12-29.
//
#include <jni.h>
#include <string>

#ifndef _Included_com_example_testbreakpad_BreadpadException
#define _Included_com_example_testbreakpad_BreadpadException
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_testbreakpad_BreadpadException
 * Method:    init
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_example_testbreakpad_BreadpadException_init
        (JNIEnv *, jobject, jstring);

/*
 * Class:     com_example_testbreakpad_BreadpadException
 * Method:    stringFromJNI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_testbreakpad_BreadpadException_stringFromJNI
        (JNIEnv *, jobject);

/*
 * Class:     com_example_testbreakpad_BreadpadException
 * Method:    breakSomething
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_testbreakpad_BreadpadException_breakSomething
        (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
