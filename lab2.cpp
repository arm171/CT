#include <iostream>
#include <string>

class TextTransformer {
private:
    const std::string base = "abcdefghijklmnopqrstuvwxyz";
    const std::string shifted = "mnopqrstuvwxyzabcdefghijkl";

public:
    std::string transform(const std::string& text) {
        std::string result;
        result.reserve(text.size());  

        for (char symbol : text) {
            size_t pos = base.find(symbol);
            if (pos != std::string::npos) {
                result += shifted[pos];
            }
            else {
                result += symbol;
            }
        }

        return result;
    }
};

int main() {
    TextTransformer transformer;
    std::string userInput;

    std::cout << "Enter your text (lowercase only): ";
    std::getline(std::cin, userInput);

    std::string output = transformer.transform(userInput);

    std::cout << "Transformed text: " << output << std::endl;

    return 0;
}
