#include "utils.h"

#include <iostream>
#include <fstream>

using namespace std;

void Utils::showProgressBar()
{
    cout << "\nProcessing...\n";

    for(int i = 0; i <= 100; i += 10)
    {
        cout << "\r[";

        int bars = i / 10;

        for(int j = 0; j < bars; j++)
            cout << "#";

        for(int j = bars; j < 10; j++)
            cout << "-";

        cout << "] " << i << "%";

        cout.flush();
    }

    cout << endl;
}

long long Utils::getFileSize(const string& filename)
{
    ifstream file(filename, ios::binary | ios::ate);

    if(!file)
        return -1;

    return static_cast<long long>(file.tellg());
}

void Utils::success(const string& message)
{
    cout << "\n[SUCCESS] "
         << message
         << endl;
}

void Utils::error(const string& message)
{
    cout << "\n[ERROR] "
         << message
         << endl;
}
