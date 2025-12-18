#pragma once
#include <string>
#include <filesystem>
#include <mutex>

namespace security
{
    class Logger
    {
    public:
        Logger(const std::filesystem::path& logFile);
        void log(const std::string& message);

    private:
        std::filesystem::path m_logFile;
        std::mutex m_mutex;
    };
}
