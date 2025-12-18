#pragma once
#include "Blocklist.h"
#include "Logger.h"
#include <filesystem>

namespace security
{
    class Scanner
    {
    public:
        Scanner(const std::filesystem::path& folder, Blocklist& blocklist, Logger& logger);
        void scan_file(const std::filesystem::path& file);
        void scan_all();

    private:
        std::filesystem::path m_folder;
        Blocklist& m_blocklist;
        Logger& m_logger;
    };
}
