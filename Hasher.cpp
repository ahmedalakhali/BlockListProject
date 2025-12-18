#include "Hasher.h"
#include <openssl/evp.h>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

namespace security
{
    string sha256_file(const filesystem::path& filePath)
    {
        ifstream file(filePath, ios::binary);
        if (!file) return "";

        EVP_MD_CTX* ctx = EVP_MD_CTX_new();
        const EVP_MD* md = EVP_sha256();

        EVP_DigestInit_ex(ctx, md, nullptr);

        char buffer[4096];
        while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0)
        {
            EVP_DigestUpdate(ctx, buffer, file.gcount());
        }

        unsigned char hash[EVP_MAX_MD_SIZE];
        unsigned int hashLen = 0;
        EVP_DigestFinal_ex(ctx, hash, &hashLen);
        EVP_MD_CTX_free(ctx);

        std::ostringstream oss;
        for (unsigned int i = 0; i < hashLen; i++)
        {
            oss << hex << setw(2) << setfill('0') << (int)hash[i];
        }

        return oss.str();
    }
}
