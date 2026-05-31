#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>

class PasswordChecker
{
public:
    static std::string checkStrength(const std::string& password);
};

#endif
