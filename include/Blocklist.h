#pragma once
#include <string>
#include <unordered_set>
#include <filesystem>

namespace security
{
    class Blocklist
    {
    public:
        Blocklist(const std::filesystem::path& path);
        void load();
        bool contains(const std::string& hash) const;

    private:
        std::filesystem::path m_path;
        std::unordered_set<std::string> m_hashes;
    };
}
