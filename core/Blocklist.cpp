#include "Blocklist.h"
#include <fstream>
#include <iostream>
using namespace std;

namespace security
{
    Blocklist::Blocklist(const filesystem::path& path)
        : m_path(path)
    {
        load();
    }

    void Blocklist::load()
    {
        m_hashes.clear();
        ifstream file(m_path);
        if (!file)
        {
            cerr << "Blocklist not found: " << m_path << "\n";
            return;
        }

        string line;
        while (getline(file, line))
        {
            if (!line.empty())
                m_hashes.insert(line);
        }
    }

    bool Blocklist::contains(const string& hash) const
    {
        return m_hashes.find(hash) != m_hashes.end();
    }
}
