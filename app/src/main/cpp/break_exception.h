//
// Created by xhp on 19-1-10.
//

#ifndef TESTBREAKPAD_BREAK_EXCEPTION_H
#define TESTBREAKPAD_BREAK_EXCEPTION_H
#include "breakpad/client/linux/handler/minidump_descriptor.h"
#include "breakpad/client/linux/handler/exception_handler.h"

void initBreakpad(const char* path, google_breakpad::ExceptionHandler *handler);
void doSomething();

#endif //TESTBREAKPAD_BREAK_EXCEPTION_H
