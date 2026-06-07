module;

// Global module fragment - standard library headers go here
#include <vector>
#include <memory>

export module Vortex3D.Mesh;

export namespace Vortex3D {

    // Forward declarations for our topology pointers
    struct Vertex;
    struct HalfEdge;
    struct Face;

    export struct Vertex {
        float x, y, z;
        HalfEdge* edge = nullptr; // One of the half-edges leaving this vertex
    };

    export struct HalfEdge {
        Vertex* vertex = nullptr; // Vertex at the start of this half-edge
        HalfEdge* pair = nullptr; // The opposite half-edge
        HalfEdge* next = nullptr; // The next half-edge in the face loop
        Face* face = nullptr;     // The face this half-edge belongs to
    };

    export struct Face {
        HalfEdge* edge = nullptr; // One of the half-edges bounding this face
    };

    export class Mesh {
    private:
        std::vector<std::unique_ptr<Vertex>> vertices;
        std::vector<std::unique_ptr<HalfEdge>> half_edges;
        std::vector<std::unique_ptr<Face>> faces;

    public:
        Mesh() = default;
        
        // Disable copying to enforce strict memory ownership
        Mesh(const Mesh&) = delete;
        Mesh& operator=(const Mesh&) = delete;
        Mesh(Mesh&&) noexcept = default;
        Mesh& operator=(Mesh&&) noexcept = default;

        // Core memory allocators for topology
        Vertex* add_vertex(float x, float y, float z) {
            vertices.push_back(std::make_unique<Vertex>(Vertex{x, y, z, nullptr}));
            return vertices.back().get();
        }
    };
}
