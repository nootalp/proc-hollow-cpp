# include "ShellcodeConverter.h"

using namespace std;
using namespace ProcessHollow;

vector<uint8_t> ShellcodeConverter::ConvertRawStringToByteArray(const string& rawString) {
    if (rawString.length() % 2 != 0)
        throw invalid_argument("String should have an even number of characters.");

    vector<uint8_t> byteArray;
    byteArray.reserve(rawString.length() / 2);

    for (size_t i = 0; i < rawString.length(); i += 2) {
        string byteStr = rawString.substr(i, 2);
        uint8_t byte = static_cast<uint8_t>(stoi(byteStr, nullptr, 16));
        byteArray.push_back(byte);
    }
    return byteArray;
}

vector<uint8_t> ShellcodeConverter::EncryptDecryptByteArray(vector<uint8_t>& byteArray) {
    for (auto& byte : byteArray)    byte ^= 54;
    return byteArray;
}

void ShellcodeConverter::PrintByteArray(const vector<uint8_t>& byteArray) {
    cout << "byte[] shellcode = new byte[" << byteArray.size() << "] { ";
    for (size_t i = 0; i < byteArray.size(); ++i) {
        cout << "\\x" << hex << setw(2) << setfill('0') << static_cast<int>(byteArray[i]);
        if (i != byteArray.size() - 1)  cout << ", ";
    }
    cout << " };" << endl;
}
