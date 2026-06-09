package com.vortex3d.app

import android.app.Activity
import android.os.Bundle

class VortexActivity : Activity() {
    private lateinit var surfaceView: VortexSurfaceView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        
        surfaceView = VortexSurfaceView(this)
        setContentView(surfaceView)
    }
}
