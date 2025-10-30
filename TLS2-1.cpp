#include <iostream>
#include <string>
#include <cctype>

std::string reverseString(const std::string &s) {
    std::string r = s;
    int i = 0, j = (int)r.size() - 1;
    while (i < j) {
        char tmp = r[i];
        r[i] = r[j];
        r[j] = tmp;
        ++i; --j;
    }
    return r;
}

bool isVowel(char c) {
    char C = std::toupper((unsigned char)c);
    return (C=='A' || C=='E' || C=='I' || C=='O' || C=='U');
}

int main() {
    std::string word;
    std::cout << "Masukkan kata (letters only): ";
    std::getline(std::cin, word);

    if (word.empty()) {
        std::cerr << "Kata kosong.\n";
        return 1;
    }

    int asciiFirst = static_cast<int>(word[0]);

    std::string noVowel;
    for (char c : word) {
        if (!isVowel(c)) noVowel.push_back(c);
    }

    std::string rev = reverseString(noVowel);

    int len = (int)rev.size();
    int pos = (len + 1) / 2;

    std::string asciiStr = std::to_string(asciiFirst);
    std::string left = rev.substr(0, pos);
    std::string right = rev.substr(pos);

    std::string password = left + asciiStr + right;
    std::cout << "Password hasil mesin: " << password << "\n";

    return 0;
}
