#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

class EncoderDecoder {
private:
    vector<vector<char>> matrix;
    string sentence;
    int rows;

public:
    EncoderDecoder(const string& inputSentence, int numRows) : sentence(inputSentence), rows(numRows) {
        createMatrix();
    }

    // funkcia matric sarqelu
    void createMatrix() {
        int len = sentence.length();
        int cols = (len + rows - 1) / rows;
        matrix = vector<vector<char>>(rows, vector<char>(cols, ' '));
        int index = 0;
        for (int j = 0; j < cols && index < len; ++j) {
            for (int i = 0; i < rows && index < len; ++i) {
                matrix[i][j] = sentence[index++];
            }
        }
    }

     //matricy cucadrelu funkcia
    void displayMatrix() {
        cout << "Matrix:" << endl;
        for (const vector<char>& row : matrix) {
            for (char elem : row) {
                cout << elem << ' ';
            }
            cout << endl;
        }
    }

   
   //matricov kodavorac naxadasutyun stanal
    string encodeMatrix() {
        string encoded;
        for (const vector<char>& row : matrix) {
            for (char elem : row) {
                encoded += elem;
            }
        }
        return encoded;
    }

    

    // RLE 
    string encodeRLE(const string& input) {
        unordered_map<char, int> frequencyMap;

        for (char ch : input) {
            if (ch != ' ') {
                frequencyMap[ch]++;
            }
        }

        ostringstream encoded;
        for (const auto& entry : frequencyMap) {
            encoded << entry.first << entry.second;
        }
        
        return encoded.str();
    }
};

int main() {
    string sentence;
    int rows;
    cout << "Naxadasutyun: ";
    getline(cin, sentence);
    cout << "Enter i: ";
    cin >> rows;

    EncoderDecoder encoderDecoder(sentence, rows);
    encoderDecoder.displayMatrix(); 
    string matrixEncodedSentence = encoderDecoder.encodeMatrix();
    cout << "Toxer-Syuner: " << matrixEncodedSentence << endl;

    string rleEncodedSentence = encoderDecoder.encodeRLE(matrixEncodedSentence);
    cout << "RLE_ov: " << rleEncodedSentence << endl;

    
    return 0;
}
