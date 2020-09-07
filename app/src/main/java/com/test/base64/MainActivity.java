package com.test.base64;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    public static String TAG = "ceshiFromJava";
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
      //  tv.setText();
        StringBuffer sb = new StringBuffer();

        base64.Base64Encode(sb,stringFromJNI().toCharArray(),stringFromJNI().length());
        String encoded = sb.toString();
        Log.d(TAG, "onCreate: " + encoded);
       // sb.delete(0,sb.length());
        sb.setLength(0);
        base64.Base64Decode(sb,encoded.toCharArray(),encoded.length());
        Log.d(TAG, "onCreate: " + sb.toString());
        tv.setText(stringFromJNI());

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
