#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

class Encryption
{
public:
    static bool encryptFile(const std::string& inputFile,
                            const std::string& outputFile,
                            const std::string& password);

    static bool decryptFile(const std::string& inputFile,
                            const std::string& outputFile,
                            const std::string& password);
};

#endif
