#include "password.h"

#include <cctype>

using namespace std;

string PasswordChecker::checkStrength(const string& password)
{
    bool upper = false;
    bool lower = false;
    bool digit = false;
    bool special = false;

    for(char ch : password)
    {
        if(isupper(ch))
            upper = true;

        else if(islower(ch))
            lower = true;

        else if(isdigit(ch))
            digit = true;

        else
            special = true;
    }

    int score = 0;

    if(password.length() >= 8)
        score++;

    if(upper)
        score++;

    if(lower)
        score++;

    if(digit)
        score++;

    if(special)
        score++;

    if(score <= 2)
        return "Weak";

    if(score <= 4)
        return "Medium";

    return "Strong";
}
