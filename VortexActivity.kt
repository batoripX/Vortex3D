package com.vortex3d.app
import android.app.Activity
import android.os.Bundle

class VortexActivity : Activity() {
    companion object {
        init {
            System.loadLibrary("vortex3d_jni")
        }
    }
    private lateinit var surfaceView: VortexSurfaceView
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        surfaceView = VortexSurfaceView(this)
        setContentView(surfaceView)
    }
}
