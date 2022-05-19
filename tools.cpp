#include "tools.h"
#include <string>
#include <locale>
#include <vector>

std::string toupper(std::string str) {
    std::locale loc;

    for (int i = 0; i < str.length(); i++) {
        str[i] = std::toupper(str[i], loc);
    }
    return str;
}

std::vector<std::string> split_string(const std::string &str) {
    std::vector<std::string> vec{};
    std::string t{};
    for (char i: str) {
        if (i != '.') {
            t += i;
        } else {
            vec.push_back(t);
            t = "";
        }
    }
    vec.push_back(t);
    return vec;
}

bool validate(std::string str, std::string type) {
    if (type != "MP4" && type != "JPG" && type != "LRV" && type != "THM")  {
         return false;
    }

    if (str.at(0) != 'G' || str.length() <4) {
        return false;
    }

    for (char i: str) {
        if (i == '-') {
            return false;
        }
    }
    return true;
}
