#pragma once
#include "Scanner.h"
#include <filesystem>

namespace security
{
    void monitor_folder(const std::filesystem::path& folder, Scanner& scanner);
}
