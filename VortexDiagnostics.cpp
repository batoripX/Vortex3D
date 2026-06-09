module;
#include <fstream>
#include <string_view>
#include <cstdint>

export module Vortex3D.Diagnostics;

export namespace Vortex3D {

    export enum class ErrorLevel : uint32_t {
        Info = 0,
        Warning = 1,
        Critical = 2
    };

    export struct DiagnosticPayload {
        uint32_t level;
        const char* systemContext;
        const char* message;
    };

    export class DiagnosticManager {
    private:
        std::ofstream logStream;
        
    public:
        void initialize(const char* storagePath) {
            std::string path = std::string(storagePath) + "/vortex_errors.log";
            logStream.open(path, std::ios::out | std::ios::trunc);
            if (logStream.is_open()) {
                logStream << "[Vortex3D Engine Diagnostics Initialized]\n";
                logStream.flush();
            }
        }

        void writeError(DiagnosticPayload payload) {
            if (!logStream.is_open()) return;

            const char* levelStr = "INFO";
            if (payload.level == 1) levelStr = "WARNING";
            if (payload.level == 2) levelStr = "CRITICAL";

            logStream << "[" << levelStr << "][" << payload.systemContext << "] " 
                      << payload.message << "\n";
            logStream.flush();
        }
    };
}
