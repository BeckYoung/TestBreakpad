package com.example.testbreakpad;

public final class BreadpadException {

    static {
        System.loadLibrary("native-lib");
    }
    private static final BreadpadException instance=new BreadpadException();

    public static BreadpadException getInstance() {
        return instance;
    }

    public native void init(String path);

    public native String stringFromJNI();

    public native void breakSomething();
}
