# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

#set(CMAKE_ANDROID_ARM_MODE arm)
# 引入ASM汇编器,项目中文件breakpad_getcontext.S使用了汇编语言
enable_language(ASM)

add_library(
             native-lib

             SHARED
             src/main/cpp/native-lib.cpp
             src/main/cpp/break_exception.cpp )

add_library(
             breakpad_client

             STATIC
             src/main/cpp/breakpad/client/linux/crash_generation/crash_generation_client.cc
             src/main/cpp/breakpad/client/linux/handler/exception_handler.cc
             src/main/cpp/breakpad/client/linux/handler/minidump_descriptor.cc
             src/main/cpp/breakpad/client/linux/log/log.cc
             src/main/cpp/breakpad/client/linux/minidump_writer/linux_dumper.cc
             src/main/cpp/breakpad/client/linux/minidump_writer/linux_ptrace_dumper.cc
             src/main/cpp/breakpad/client/linux/minidump_writer/minidump_writer.cc
             src/main/cpp/breakpad/client/linux/microdump_writer/microdump_writer.cc
             src/main/cpp/breakpad/client/linux/dump_writer_common/ucontext_reader.cc
             src/main/cpp/breakpad/client/linux/dump_writer_common/seccomp_unwinder.cc
             src/main/cpp/breakpad/client/linux/dump_writer_common/thread_info.cc
             src/main/cpp/breakpad/client/minidump_file_writer.cc
             src/main/cpp/breakpad/common/android/breakpad_getcontext.S
             src/main/cpp/breakpad/common/convert_UTF.c
             src/main/cpp/breakpad/common/md5.cc
             src/main/cpp/breakpad/common/string_conversion.cc
             src/main/cpp/breakpad/common/linux/elfutils.cc
             src/main/cpp/breakpad/common/linux/file_id.cc
             src/main/cpp/breakpad/common/linux/guid_creator.cc
             src/main/cpp/breakpad/common/linux/linux_libc_support.cc
             src/main/cpp/breakpad/common/linux/memory_mapped_file.cc
             src/main/cpp/breakpad/common/linux/safe_readlink.cc )

#target_include_directories(
#                            breakpad_client
#                            PRIVATE
#                            src/main/cpp/breakpad/common/android/include
#                            src/main/cpp/breakpad/ )
include_directories(
                    src/main/cpp/breakpad/common/android/include
                    src/main/cpp/breakpad/ )

find_library(
              log-lib
              log )

target_link_libraries(
                       native-lib breakpad_client
                       ${log-lib} )