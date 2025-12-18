#pragma once

#include <string>
#include <filesystem>

namespace security
{
    std::string sha256_file(const std::filesystem::path& filePath);
}
