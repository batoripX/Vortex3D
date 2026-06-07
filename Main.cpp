module;

#include <iostream>
#include <memory>

// Import our custom modern C++20 mesh module
import Vortex3D.Mesh;

int main() {
    std::cout << "Initializing Vortex3D Engine Core..." << std::endl;

    // Instantiate our clean topology state container
    auto engine_mesh = std::make_unique<Vortex3D::Mesh>();

    // Allocate a basic triangle point setup to verify memory lanes are solid
    Vortex3D::Vertex* v1 = engine_mesh->add_vertex(0.0f, 1.0f, 0.0f);
    Vortex3D::Vertex* v2 = engine_mesh->add_vertex(-1.0f, -1.0f, 0.0f);
    Vortex3D::Vertex* v3 = engine_mesh->add_vertex(1.0f, -1.0f, 0.0f);

    if (v1 && v2 && v3) {
        std::cout << "Vortex3D Engine: Core Mesh topology loaded successfully." << std::endl;
        std::cout << "Vertex memory allocation verified." << std::endl;
    } else {
        std::cerr << "Vortex3D Engine: Allocation failure in core memory tracking." << std::endl;
        return 1;
    }

    std::cout << "Vortex3D Engine: System idling smoothly. Ready for JNI hook." << std::endl;
    return 0;
}
