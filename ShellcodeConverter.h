#ifndef SHELLCODECONVERTER_H
#define SHELLCODECONVERTER_H

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

namespace ProcessHollow {
    class ShellcodeConverter {
    public:
        static vector<uint8_t> ConvertRawStringToByteArray(const string& rawString);
        static vector<uint8_t> EncryptDecryptByteArray(vector<uint8_t>& byteArray);
        static void PrintByteArray(const vector<uint8_t>& byteArray);
    };
}

#endif /* SHELLCODECONVERTER_H */
