#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <cstring>

void generateAndSaveMatrix(const std::string& filename) {
    const int rows = 2;
    const int cols = 3;
    std::vector<std::vector<int>> matrix1(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> matrix2(rows, std::vector<int>(cols));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); // Random numbers between 1 and 100

    // Generate random numbers for both matrices
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            matrix1[i][j] = dis(gen);
            matrix2[i][j] = dis(gen);
        }
    }

    // Write the matrices to the file
    std::ofstream outFile(filename);
    if(outFile.is_open()) {
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                outFile << matrix1[i][j] << " ";
            }
            outFile << std::endl;
        }
        outFile << std::endl; // Separate the two matrices with a blank line
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                outFile << matrix2[i][j] << " ";
            }
            outFile << std::endl;
        }
        outFile.close();
        std::cout << "SUCCESS" << std::endl;
    } else {
        std::cerr << "FAILURE" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if(argc != 3 || std::strcmp(argv[1], "-a") != 0) {
        std::cerr << "Usage: " << argv[0] << " -a <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[2];
    generateAndSaveMatrix(filename);

    return 0;
}