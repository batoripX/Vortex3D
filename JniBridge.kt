package com.vortex3d.app

import kotlinx.cinterop.*
import platform.android.*
import java.io.File

object VortexNativeBridge {

    init {
        try {
            // Force create the sandboxed logging directory path so std::fopen never fails
            val logDir = File("/sdcard/Android/data/com.vortex3d.app/files")
            if (!logDir.exists()) {
                logDir.mkdirs()
            }
            
            // Try loading your native binary safely
            System.loadLibrary("vortex3d_engine")
        } catch (e: Exception) {
            println("VORTEX_FATAL: Failed to initialize native engine library: ${e.message}")
        }
    }

    fun bindNativeSurface(surfaceWindowPointer: COpaquePointer?) {
        if (surfaceWindowPointer == null) return
        // C++ bridge binding logic
    }

    fun notifyDisplayResize(width: Int, height: Int) {
        if (width <= 0 || height <= 0) return
    }

    fun releaseNativeEngine() {
        // Cleanup logic
    }
}
