#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ColumnarCipher {
    int columns;

    vector<vector<char>> generateGrid(const string& text, int& rows) {
        rows = (text.size() + columns - 1) / columns;

        vector<vector<char>> grid(rows, vector<char>(columns, ' '));
        int index = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < columns && index < text.size(); ++c) {
                grid[r][c] = text[index++];
            }
        }
        return grid;
    }

public:
    explicit ColumnarCipher(int cols) : columns(cols) {}

    string encode(const string& text) {
        int rows;
        vector<vector<char>> grid = generateGrid(text, rows);
        string result;
        for (int c = 0; c < columns; ++c) {
            for (int r = 0; r < rows; ++r) {
                if (grid[r][c] != ' ') result += grid[r][c];
            }
        }
        return result;
    }

    string decode(const string& encodedText) {
        int rows;
        vector<vector<char>> grid = generateGrid(encodedText, rows);
        int index = 0;
        for (int c = 0; c < columns; ++c) {
            for (int r = 0; r < rows && index < encodedText.size(); ++r) {
                grid[r][c] = encodedText[index++];
            }
        }
        string result;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < columns; ++c) {
                if (grid[r][c] != ' ') result += grid[r][c];
            }
        }
        return result;
    }
};

int main() {
    string inputText;
    int colCount;

    cout << "Enter the text to encode: ";
    getline(cin, inputText);

    cout << "Enter number of columns: ";
    cin >> colCount;

    ColumnarCipher cipher(colCount);

    string encodedText = cipher.encode(inputText);
    cout << "Encoded Message: " << encodedText << endl;

    string decodedText = cipher.decode(encodedText);
    cout << "Decoded Message: " << decodedText << endl;

    return 0;
}
