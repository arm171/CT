#include <iostream>
#include <string>

class CaesarCipher {
    int shift;
public:
    CaesarCipher(int s) : shift(s % 26) {}

    std::string cipher(const std::string& text, int direction) {
        std::string result;
        for (char ch : text) {
            if (ch >= 'a' && ch <= 'z') {
                result += (ch - 'a' + direction * shift + 26) % 26 + 'a';
            } else {
                result += ch;
            }
        }
        return result;
    }

    std::string encrypt(const std::string& text) { return cipher(text, 1); }
    std::string decrypt(const std::string& text) { return cipher(text, -1); }
};

int main() {
    int shift;
    std::cout << "Enter shift value (0-25): ";
    std::cin >> shift;
    std::cin.ignore();

    CaesarCipher cipher(shift);

    std::string text;
    std::cout << "Enter text: ";
    std::getline(std::cin, text);

    std::cout << "Encrypted: " << cipher.encrypt(text) << "\n";
    std::cout << "Decrypted: " << cipher.decrypt(cipher.encrypt(text)) << "\n";

    return 0;
}
