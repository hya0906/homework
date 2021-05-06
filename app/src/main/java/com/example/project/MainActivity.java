package com.example.project;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ActionBar actionBar = getSupportActionBar();
        actionBar.setDisplayHomeAsUpEnabled(true);
    }
    public void onClick(View v){
        Intent i1;
        i1 = new Intent(this,MainActivity2.class);
        startActivity(i1);
//        switch(v.getId()){
////            case R.id.b1:
////                i1 = new Intent(this,MainActivity2.class);
////                startActivity(i1);
////                break;
//            case R.id.imageView1:
//                i1 = new Intent(this,MainActivity2.class);
//                startActivity(i1);
//                break;
//
//        }
    }
}