#include <iostream>

#include "encryption.h"
#include "password.h"
#include "history.h"
#include "utils.h"

using namespace std;

int main()
{
    int choice;

    string inputFile;
    string outputFile;
    string password;

    while(true)
    {
        cout << "\n=================================\n";
        cout << "    SMART ENCRYPTION TOOL\n";
        cout << "=================================\n";

        cout << "1. Encrypt File\n";
        cout << "2. Decrypt File\n";
        cout << "3. View History\n";
        cout << "4. Exit\n";

        cout << "\nEnter Choice: ";

        cin >> choice;
        cin.ignore();

        if(choice == 1)
        {
            cout << "\nInput File: ";
            getline(cin, inputFile);

            long long size =
                Utils::getFileSize(inputFile);

            if(size == -1)
            {
                Utils::error(
                    "File does not exist."
                );
                continue;
            }

            cout << "File Size: "
                 << size
                 << " bytes\n";

            cout << "Output File: ";
            getline(cin, outputFile);

            cout << "Password: ";
            getline(cin, password);

            cout << "Password Strength: "
                 << PasswordChecker::checkStrength(password)
                 << endl;

            Utils::showProgressBar();

            if(
                Encryption::encryptFile(
                    inputFile,
                    outputFile,
                    password
                )
            )
            {
                History::saveLog(
                    "Encrypt",
                    inputFile
                );

                Utils::success(
                    "File Encrypted Successfully"
                );
            }
        }

        else if(choice == 2)
        {
            cout << "\nEncrypted File: ";
            getline(cin, inputFile);

            long long size =
                Utils::getFileSize(inputFile);

            if(size == -1)
            {
                Utils::error(
                    "File does not exist."
                );
                continue;
            }

            cout << "File Size: "
                 << size
                 << " bytes\n";

            cout << "Output File: ";
            getline(cin, outputFile);

            cout << "Password: ";
            getline(cin, password);

            Utils::showProgressBar();

            if(
                Encryption::decryptFile(
                    inputFile,
                    outputFile,
                    password
                )
            )
            {
                History::saveLog(
                    "Decrypt",
                    inputFile
                );

                Utils::success(
                    "File Decrypted Successfully"
                );
            }
        }

        else if(choice == 3)
        {
            cout << "\n========= HISTORY =========\n";

            History::showHistory();
        }

        else if(choice == 4)
        {
            cout << "\nThank you for using the tool.\n";
            break;
        }

        else
        {
            Utils::error(
                "Invalid Choice"
            );
        }
    }

    return 0;
}
