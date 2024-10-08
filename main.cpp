#include <iostream>
#include <filesystem>
#include <string>
#include <regex>
#include <vector>

namespace fs = std::filesystem;

    //Function for LIST ALL FILES (Current Directory)
int listAllFiles(const fs::path& path) {
    int directoryCount= 0;
    std::cout << "LISTING ALL DIRECTORIES: "<< std::endl;
    std::cout << "------------------------------------"<< std::endl;
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) { //This one is for the file counter inside the Directory...
            std::cout <<entry.path() .filename().string()<< std::endl;
            directoryCount++;
        }
    }
    return directoryCount;
}

//TO show List Files based on a extension
void listFilesByExtension(const fs::path& path, const std::string& extension) {
    std::cout << "Listing all files with extention" << extension <<" in directory: " << path << std::endl;
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.path().extension() == extension) {
            std::cout << entry.path().filename() .string() <<std::endl;
        }
    }
}

//TO show List Files based on a pattern
void listFilesByPattern(const fs::path& path, const std::string& pattern) {
    std::cout << "Listing files matching pattern " << pattern << " in directory: " << path << std::endl;
    std::regex reg(pattern);
    for (const auto& entry : fs::directory_iterator(path)) {
        if (std:: regex_match(entry.path() .filename() .string(), reg)) {
            std:: cout << entry.path() .filename() .string() << std::endl;
        }
    }
}

void createDirectory(const fs::path& path) {
    if (fs:: create_directory(path)) {
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "Current Directory: " << path << std::endl;
        std::cout << "DIRECTORY SUCCESSFULLY CREATED" << std::endl;
    } else {
        std::cout << "Failed to create directory, or directory already exists." << std::endl; 
    }
}

//To change the Working Directory
void changeDirectory(fs::path& currentPath) {
    int option;
    std::cout << "CHANGE DIRECTORY\n";
    std::cout << "--------------------\n";
    std::cout << "1. Step by Step Backward\n";
    std::cout << "2. Go to Root Directory\n";
    std::cout << "3. Forward Directory\n";
    std::cout << "Enter the number: ";
    std::cin >> option;

    switch (option) {
        case 1:
            if (currentPath.has_parent_path()) {
                currentPath = currentPath.parent_path();
                std::cout << "Moved to parent directory: " <<currentPath << std::endl;    
            } else {
                std::cout << "Already at the root directory." << std::endl;
            }
            break;
        case 2:
            currentPath = currentPath.root_path();
            std::cout<< "Moved to the root directory: " << currentPath << std::endl;
            break;
        case 3: {
            std::string newPath;
            std::cout << "Please Enter The Directory Name: ";
            std::cin.ignore();
            std::getline(std::cin, newPath);
            fs::path newDirectoryPath = fs::absolute(currentPath/newPath);
            if (fs::exists(newDirectoryPath) && fs::is_directory(newDirectoryPath)) {
                currentPath = newDirectoryPath;
                std::cout << "Current Directory: "<< currentPath << std::endl;
            } else {
                std::cout << "Invalid directory!" << std::endl;
            }
            break;
        }
        default:
            std::cout << "Invalid option." << std::endl;
            break;
        }           
    }
}
//Fcae of the Code
void mainMenu() {
    fs::path current Path = fs::current_path();
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
            

            iswitch (listChoice) {
                    case 1: {
                        std::cout << "List of All Files\n";
                        int totalList = listAllDirectories(currentPath);
                        std::cout << "---------------------------------------" << std::endl;
                        std::cout << "Total Files: " << totalList << std::endl;
                        break;
                    }
                    case 2: {
                        std::string extension;
                        std::cout << "Enter the file extension (e.g., .txt): ";
                        std::cin >> extension;
                        listFilesByExtension(currentPath, extension);
                        break;
                    }
                    case 3: {
                        std::string pattern;
                        std::cout << "Enter the file pattern (e.g., .*\\.txt): ";
                        std::cin.ignore();
                        std::getline(std::cin, pattern);
                        listFilesByPattern(currentPath, pattern);
                        break;
                    }
                    default:
                        std::cout << "Invalid choice." << std::endl;
                        break;
                }
                break;
        }
        case 2: {
            std::string dirName;
            std::cout << "Enter the Directory Name: ";
            std::cin.ignore(); //For clearing the new line characters
            std::getline(std::cin, dirName);
            createDirectory(currentPath / dirName);
            break;
        }
        case 3: 
            std::cout<<currentPath<<std::endl;
            changeDirectory(currentPath);
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
}
