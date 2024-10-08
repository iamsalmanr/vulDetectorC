#include <iostream>
#include <cstring>

void vulnerableFunction(char* userInput) {
    // Fixed size buffer with no bounds checking
    char buffer[16];

    // Vulnerability: strcpy does not check if userInput exceeds buffer size
    std::strcpy(buffer, userInput);

    // Print user input
    std::cout << "User input: " << buffer << std::endl;
}

int main() {
    // Input buffer with much larger size
    char input[100];

    std::cout << "Enter some input: ";
    std::cin >> input;  // Vulnerability: cin does not limit input size

    // Call vulnerable function
    vulnerableFunction(input);

    return 0;
}
