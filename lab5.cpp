#include <iostream>
#include <string>
#include <sstream>

class RunLengthEncoding {
public:
    std::string compress(const std::string& data) {
        std::ostringstream result;
        int counter = 1;

        for (size_t i = 0; i < data.length(); ++i) {
            if (i == data.length() - 1 || data[i] != data[i + 1]) {
                result << data[i] << static_cast<char>(counter);
                counter = 1;
            } else {
                ++counter;
            }
        }

        return result.str();
    }

    std::string decompress(const std::string& data) {
        std::ostringstream result;

        for (size_t i = 0; i < data.length(); ++i) {
            char character = data[i];
            ++i;
            int frequency = static_cast<int>(data[i]);
            result << std::string(frequency, character);
        }

        return result.str();
    }
};

int main() {
    RunLengthEncoding rle;
    std::string userInput;

    std::cout << "Enter text to compress: ";
    std::getline(std::cin, userInput);

    std::string compressed = rle.compress(userInput);
    std::cout << "Compressed text: " << compressed << std::endl;

    std::string decompressed = rle.decompress(compressed);
    std::cout << "Decompressed text: " << decompressed << std::endl;

    return 0;
}
