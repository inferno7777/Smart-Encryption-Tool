#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils
{
public:
    static void showProgressBar();

    static long long getFileSize(
        const std::string& filename
    );

    static void success(
        const std::string& message
    );

    static void error(
        const std::string& message
    );
};

#endif
