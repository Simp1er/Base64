//
// Created by Simp1er on 2020-09-07.
//

#include "base64.h"
using namespace std;
string base64::base64Encode(string &dest, char *src, int length) {
    for (int i = 0; i < length; i += 3) {
        dest.push_back(constants[(src[i] >> 2 & 0x3f)]);
        if ((i + 1) == length) {
            dest.push_back(constants[(src[i] << 4) & 0x30]);
            dest.push_back(suffix + suffix);
            break;
        }
        dest.push_back(constants[((src[i] << 4) & 0x30) | (src[i + 1] >> 4 & 0xf)]);
        if (i + 2 == length) {
            dest.push_back(constants[((src[i + 1] << 2) & 0x3c)]);
            dest.push_back(suffix);
            break;

        }
        dest.push_back(constants[(((src[i + 1] << 2) & 0x3c) | ((src[i + 2] >> 6) & 0x3))]);
        dest.push_back(constants[(src[i + 2] & 0x3f)]);
    }
    return dest;
}

string base64::base64Decode(string& dest, char *src, int length) {
    for (int i = 0; i < length; i += 4) {

        dest.push_back((char) (((getIndex(src[i]) << 2) & 0xfc) | ((getIndex(src[i + 1]) >> 4) & 0x3)));
        if (src[i + 2] == suffix) {
            break;
        }
        dest.push_back((char) (((getIndex(src[i + 1]) << 4) & 0xf0) | ((getIndex(src[i + 2]) >> 2) & 0xf)));
        if (src[i + 3] == suffix) {
            break;
        }
        dest.push_back((char) (((getIndex(src[i + 2]) << 6) & 0xc0) | ((getIndex(src[i + 3])) & 0x3f)));
    }
    return dest;
}

int base64::getIndex(char src) {

     size_t  index = constants.find(src);
     if(index != string::npos){
         return index;
     }
     else{
         return 0xff;
     }

}
