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
                            const std::string& outputFile#include "encryption.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool Encryption::encryptFile(const string& inputFile,
                             const string& outputFile,
                             const string& password)
{
    if(password.empty())
    {
        cout << "Password cannot be empty!\n";
        return false;
    }

    ifstream fin(inputFile, ios::binary);

    if(!fin)
    {
        cout << "Cannot open input file.\n";
        return false;
    }

    vector<char> data(
        (istreambuf_iterator<char>(fin)),
        istreambuf_iterator<char>()
    );

    fin.close();

    for(size_t i = 0; i < data.size(); i++)
    {
        data[i] ^= password[i % password.size()];
    }

    ofstream fout(outputFile, ios::binary);

    if(!fout)
    {
        cout << "Cannot create output file.\n";
        return false;
    }

    fout.write(data.data(), data.size());
    fout.close();

    cout << "Encryption completed successfully.\n";

    return true;
}

bool Encryption::decryptFile(const string& inputFile,
                             const string& outputFile,
                             const string& password)
{
    if(password.empty())
    {
        cout << "Password cannot be empty!\n";
        return false;
    }

    ifstream fin(inputFile, ios::binary);

    if(!fin)
    {
        cout << "Cannot open encrypted file.\n";
        return false;
    }

    vector<char> data(
        (istreambuf_iterator<char>(fin)),
        istreambuf_iterator<char>()
    );

    fin.close();

    for(size_t i = 0; i < data.size(); i++)
    {
        data[i] ^= password[i % password.size()];
    }

    ofstream fout(outputFile, ios::binary);

    if(!fout)
    {
        cout << "Cannot create output file.\n";
        return false;
    }

    fout.write(data.data(), data.size());
    fout.close();

    cout << "Decryption completed successfully.\n";

    return true;
}
                            const std::string& password);
};

#endif
