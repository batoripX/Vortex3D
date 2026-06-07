// 1. Global module fragment: Where standard preprocessor headers MUST live
module;

#include <vector>

// 2. Module declaration
export module Vortex3D.Mesh;

// 3. Exported namespace container
export namespace Vortex3D {

    struct HalfEdge;
    struct Face;

    struct Vertex {
        float x, y, z;
        HalfEdge* edge = nullptr;
    };

    struct HalfEdge {
        Vertex* origin = nullptr;
        HalfEdge* twin = nullptr;
        HalfEdge* next = nullptr;
        Face* face = nullptr;
    };

    struct Face {
        HalfEdge* edge = nullptr;
    };

    class Mesh {
    private:
        std::vector<Vertex*> vertices;
        std::vector<HalfEdge*> edges;
        std::vector<Face*> faces;

    public:
        Mesh() = default;
        ~Mesh() {
            for (auto v : vertices) delete v;
            for (auto e : edges) delete e;
            for (auto f : faces) delete f;
        }

        Vertex* add_vertex(float x, float y, float z) {
            auto v = new Vertex{x, y, z};
            vertices.push_back(v);
            return v;
        }
    };
}
