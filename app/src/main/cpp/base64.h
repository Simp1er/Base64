//
// Created by Simp1er on 2020-09-07.
//

#ifndef BASE64_BASE64_H
#define BASE64_BASE64_H

#include <iostream>
//#include <string>
using namespace std;
class base64 {
    // using namespace std;
private:
    string constants;
    char suffix;

    /*
     * {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                    'w', 'x', 'y', 'z', '0', '1', '2', '3',
                    '4', '5', '6', '7', '8', '9', '+', '/'};
     */

    int getIndex(char src);

public:
    base64(string constants= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", char suffix='=') {

        this->constants = constants;
        this->suffix = '=';
    }
    std::string base64Encode(std::string& dest, char *src, int length);

    std::string base64Decode(std::string& dest, char *src, int length);


};


#endif //BASE64_BASE64_H
