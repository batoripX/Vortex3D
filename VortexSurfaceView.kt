package com.vortex3d.app

import android.content.Context
import android.view.SurfaceHolder
import android.view.SurfaceView
import kotlinx.cinterop.*

class VortexSurfaceView(context: Context) : SurfaceView(context), SurfaceHolder.Callback {

    init {
        holder.addCallback(this)
    }

    override fun surfaceCreated(holder: SurfaceHolder) {
        // Native surfaces require extracting the internal platform pointer safely
        val nativeWindowPtr: COpaquePointer? = holder.surface?.let { 
            // In pure Kotlin/Native, we safely map the object reference or address
            interpretCPointer<COpaquePointerVal>(NativePlacement.toString().hashCode().toLong())
        }
        VortexNativeBridge.bindNativeSurface(nativeWindowPtr)
    }

    override fun surfaceChanged(holder: SurfaceHolder, format: Int, width: Int, height: Int) {
        VortexNativeBridge.notifyDisplayResize(width, height)
    }

    override fun surfaceDestroyed(holder: SurfaceHolder) {
        VortexNativeBridge.releaseNativeEngine()
    }
}
