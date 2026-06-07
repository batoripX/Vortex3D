package com.vortex3d.app

import android.content.Context
import android.view.SurfaceHolder
import android.view.SurfaceView

class VortexSurfaceView(context: Context) : SurfaceView(context), SurfaceHolder.Callback {

    init {
        holder.addCallback(this)
    }

    override fun surfaceCreated(holder: SurfaceHolder) {
        NativeEngine.initVulkan(holder.surface)
    }

    override fun surfaceChanged(holder: SurfaceHolder, format: Int, width: Int, height: Int) {
        NativeEngine.resizeDisplay(width, height)
    }

    override fun surfaceDestroyed(holder: SurfaceHolder) {
        NativeEngine.cleanupVulkan()
    }
}

object NativeEngine {
    init {
        System.loadLibrary("vortex3d_jni")
    }

    external fun initVulkan(surface: Any)
    external fun resizeDisplay(width: Int, height: Int)
    external fun cleanupVulkan()
}
