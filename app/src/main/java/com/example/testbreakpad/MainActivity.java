package com.example.testbreakpad;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import java.io.File;


public class MainActivity extends AppCompatActivity {
    private static final String TAG = MainActivity.class.getSimpleName();
    private String breakPath;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        File file = getExternalFilesDir(null);
        if (file != null) {
            breakPath = file.getPath();
            Log.d(TAG, "path=" + breakPath);
            BreadpadException.getInstance().init(breakPath);
        }
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(BreadpadException.getInstance().stringFromJNI());
        findViewById(R.id.button).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!TextUtils.isEmpty(breakPath)) {
                    Log.d(TAG, "do something break");
                    BreadpadException.getInstance().breakSomething();
                }
            }
        });
    }

}
