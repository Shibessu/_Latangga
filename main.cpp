#include <iostream>
#include <filesystem>
#include <string>
#include <regex>

namespace fs = std::filesystem;

    //Function for LIST ALL FILES (Current Directory)
    int listAllFiles(const fs::path& path) {
    int fileCount= 0;
    std::cout << "LISTING ALL FILES ON THE DIRECTORY: "<< std::endl;
    std::cout << "------------------------------------"<< std::endl;
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) { //This one is for the file counter inside the Directory...
            std::cout <<entry.path() .filename().string()<< std::endl;
            fileCount++;
        }
    }
    return fileCount;
}

//TO show List Files based on a extention
void ListFilesByExtension(cons fs::path& path, const std::string& extension) {
    std::cout << "Listing all files with extention" << extention <<" in directory: " << path << std::endl;
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.path().extension() == extension) {
            std::cout << entry.path().filename() .string() <<std::endl;
        }
    }
}

//TO show List Files based on a pattern
void listFilesByPattern(const fs::path& path, const std::string& patter) {
    std::cout << "Listing files matching pattern " << pattern << " in directory: " << path << std::endl;
    std::regex reg(pattern);
    for (const auto& entry : fs::directory_iterator(path()) {
        if (std:: regex_match(entry.path() .filename() .string() << std::endl;
            std:: cout << entry.path() .filename() .string() << std::endl;
        }
    }
}

void createDirectory(const fs::path& path) {
    if (fs:: create_directoy(path)) {
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "Current Directory: " << path << std::endl;
        std::cout << "DIRECTORY SUCCESFULLY CREATED" << std::endl;
    } else {
        std::cout << "Failed to create directory, or directory already exists." << std::endl; 
    }
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
            } else {
                std::cout << "Invalid Choice." << std::endl;
                break;
            }
        case 2: {
            std::string dirName;
            std::cout << "Enter the Directory Name: ";
            std::cin.ignore(); //For clearing the new line characters
            std::getline(srd::cin, dirName);
            break;
        }
        case 3: 
            std::coutc<<currentPath<<std::endl;
            break;
        case 4:
            std::cout << "Exiting the Program.\n";
            break;
        default:
            std::cout << "Invalid Choice. Please Try Again.\n";
            break;
        }
    } while  (choice != 4);
}

int main(){
    mainMenu();
    return 0;

    
            
    

