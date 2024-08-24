#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main()
{

}

void mainMenu*() {
    fs::path current Path = fs::current_path9();
    int choice;

    do {
        std::cout << "Main Menu\n" << std::endl;
        std::cout << "-----------------------------------"<< std::endl;
        std::cout << "1. To Display List of Files\n";
        std::cout << "2. To Create New Directory\n";
        std::cout << "3. To Change The Working Directory\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter the Number: ";
        std::cin >> choice;
        std::cout << "-----------------------------------\n ";
        std::cout << " ";

        switch (choice) {
            case 1: {
            int listChoice;
            std::cout << "LIST FILE DEATIL\n";
            std::cout << "-----------------------------------\n";
            std::cout << "1. List All Files\n";
            std::cout << "2. List of Extention Files\n";
            std::cout << "3. List of the Name Wise\n";
            std::cout << "Enter your choice: ";
            std::cin >> listChoice;

            if (listChoice == 1) {
                std::cout << "List of All (*.*) Files\n";
                    int totalList = listAllFiles(currentPath);  // Get and print files
                    std::cout << "--------------------------------------- "<< std::endl;
                    std::cout << "Total Files: " << totalList << std::endl;  // Print total count
  // Correct the syntax
                    break;
                } else if (listChoice == 2) {
                    std::string extension;
                    std::cout << "Enter the file extension (e.g., .txt): ";
                    std::cin >> extension;
                    listFilesByExtension(currentPath, extension);
                    break;
                } else if (listChoice == 3) {
                    std::string pattern;
                    std::cout << "Enter the file pattern (e.g., .*\\.txt): ";
                    std::cin.ignore();
                    std::getline(std::cin, pattern);
                    listFilesByPattern(currentPath, pattern);
                    break;
                } else {
                    std::cout << "Invalid choice." << std::endl;
                    break;
                }
                break;
            }
            }

        }
    }

