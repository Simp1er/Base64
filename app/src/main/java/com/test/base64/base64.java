package com.test.base64;


public class base64 {
    private static final char[] constants = new char[]
            {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                    'w', 'x', 'y', 'z', '0', '1', '2', '3',
                    '4', '5', '6', '7', '8', '9', '+', '/'};
    public static char suffix = '=';
    private static int getIndex(char src) {
        if (src >= 'A' && src <= 'Z') {
            return (src - 'A');
        } else if (src >= 'a' && src <= 'z') {
            return ('Z' - 'A') + (src - 'a') + 1;
        } else if (src >= '0' && src <= '9') {
            return ('Z' - 'A') + ('z' - 'a') + 1 + (src - '0' + 1);
        } else if (src == '+') {
            return 62;
        } else if (src == '/')
            return 63;
        return 0xff;
    }

    public static void Base64Encode(StringBuffer dest, char[] src, int length) {

        for (int i = 0; i < length; i += 3) {
            dest.append(constants[(src[i] >> 2 & 0x3f)]);
            if ((i + 1) == length) {
                dest.append(constants[(src[i] << 4) & 0x30]);
                dest.append(suffix + suffix);
                break;
            }
            dest.append(constants[((src[i] << 4) & 0x30) | (src[i + 1] >> 4 & 0xf)]);
            if (i + 2 == length) {
                dest.append(constants[((src[i + 1] << 2) & 0x3c)]);
                dest.append(suffix);
                break;

            }
            dest.append(constants[(((src[i + 1] << 2) & 0x3c) | ((src[i + 2] >> 6) & 0x3))]);
            dest.append(constants[(src[i + 2] & 0x3f)]);
        }

    }


    public static void Base64Decode(StringBuffer dest, char[] src, int length) {

        for (int i = 0; i < length; i += 4) {

            dest.append((char) (((getIndex(src[i]) << 2) & 0xfc) | ((getIndex(src[i + 1]) >> 4) & 0x3)));
            if (src[i + 2] == suffix) {
                break;
            }
            dest.append((char) (((getIndex(src[i + 1]) << 4) & 0xf0) | ((getIndex(src[i + 2]) >> 2) & 0xf)));
            if (src[i + 3] == suffix) {
                break;
            }
            dest.append((char) (((getIndex(src[i + 2]) << 6) & 0xc0) | ((getIndex(src[i + 3])) & 0x3f)));
        }
    }

}
