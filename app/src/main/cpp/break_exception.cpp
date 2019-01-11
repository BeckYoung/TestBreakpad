//
// Created by xhp on 19-1-10.
//
#include <stdio.h>
#include "break_exception.h"

// 是否已经进行了初始化
bool isInit = false;

bool DumpCallback(const google_breakpad::MinidumpDescriptor &descriptor,
                  void *context,
                  bool succeeded) {
    printf("Dump path: %s\n", descriptor.path());
    return succeeded;
}


void Crash() {
    volatile int *a = reinterpret_cast<volatile int *>(NULL);
    *a = 1;
}

void initBreakpad(const char* path, google_breakpad::ExceptionHandler *handler) {
    if (path) {
        isInit = true;
        google_breakpad::MinidumpDescriptor descriptor("/mnt/sdcard");
        handler = new google_breakpad::ExceptionHandler(descriptor, NULL, DumpCallback, NULL, true, -1);
        //google_breakpad::ExceptionHandler eh(descriptor, NULL, DumpCallback, NULL, true, -1);
    }
}

void doSomething() {
    if (isInit) {
        Crash();
    }
}
