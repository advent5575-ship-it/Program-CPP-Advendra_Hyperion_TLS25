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

int main() {
    std::string password;
    std::cout << "Masukkan sandi: ";
    std::getline(std::cin, password);

    if (password.empty()) {
        std::cerr << "Sandi kosong.\n";
        return 1;
    }

    int n = (int)password.size();
    int start = -1, end = -1;
    for (int i = 0; i < n; ++i) {
        if (std::isdigit((unsigned char)password[i])) {
            if (start == -1) start = i;
            end = i;
        } else {
            if (start != -1 && end != -1) break;
        }
    }

    if (start == -1) {
        std::cerr << "Tidak ditemukan kode ASCII di sandi.\n";
        return 1;
    }

    std::string digitBlock = password.substr(start, end - start + 1);
    int asciiVal = std::stoi(digitBlock);
    char firstChar = static_cast<char>(asciiVal);

    std::string left = password.substr(0, start);
    std::string right = password.substr(end + 1);
    std::string revNoVowel = left + right;

    std::string noVowelOriginal = reverseString(revNoVowel);

    std::cout << "Ditemukan ASCII: " << asciiVal << " -> huruf pertama: '" << firstChar << "'\n";
    std::cout << "Bagian kata asli tanpa vokal (recovered): " << noVowelOriginal << "\n";
    std::cout << "Catatan: ini adalah kata tanpa vokal. Untuk kata Inggris lengkap, perlu dicari kemungkinan penempatan vokal.\n";

    return 0;
}
