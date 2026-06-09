package com.vortex3d.app

import kotlinx.cinterop.*
import platform.android.*
import java.io.File
import com.vortex3d.engine.interop.* // Bindings mapped from engine.def

object VortexNativeBridge {

    init {
        // Ensure diagnostic directory exists before engine loops start
        val logDir = File("/sdcard/Android/data/com.vortex3d.app/files")
        if (!logDir.exists()) {
            logDir.mkdirs()
        }
    }

    fun bindNativeSurface(surfaceWindowPointer: COpaquePointer?) {
        if (surfaceWindowPointer == null) return
        // Call your raw C++ C20 Engine directly via its binding
        vortex_api_bind_surface(surfaceWindowPointer)
    }

    fun notifyDisplayResize(width: Int, height: Int) {
        if (width <= 0 || height <= 0) return
        vortex_api_resize_display(width, height)
    }

    fun releaseNativeEngine() {
        vortex_api_shutdown()
    }
}
