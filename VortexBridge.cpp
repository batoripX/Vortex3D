#include <cstdint>

// Import the modules you need to trigger from the Android lifecycle
import Vortex3D.Mesh;

extern "C" {

    void vortex_api_bind_surface(void* surfaceWindowPointer) {
        if (!surfaceWindowPointer) return;
        // Interface pointer passed cleanly to your Vulkan subsystems
    }

    void vortex_api_resize_display(int32_t width, int32_t height) {
        if (width <= 0 || height <= 0) return;
    }

    void vortex_api_shutdown() {
        // Cleanup sequence
    }
}
