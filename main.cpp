#include <iostream>
#include <vector>
#include <algorithm>  // for find_if

class Tool {
private:
    std::string toolName;
    std::string category;
    std::string link;       // Added Tool Link field here
    std::string description;
public:
    Tool(std::string name, std::string cat, std::string lnk, std::string desc)
        : toolName(name), category(cat), link(lnk), description(desc) {}  // Modified constructor to include Tool Link

    std::string getToolName() const { return toolName; }
    std::string getCategory() const { return category; }
    std::string getLink() const { return link; }  // Getter method for Tool Link
    std::string getDescription() const { return description; }
};

class Directory {
private:
    std::vector<Tool> tools;
public:
    void addTool(const Tool& tool) {
        tools.push_back(tool);
        std::cout << "Tool added successfully!" << std::endl;
    }

    void listTools() const {
        for (auto const &tool : tools) {
            std::cout << "Name: " << tool.getToolName() << "\n";
            std::cout << "Category: " << tool.getCategory() << "\n";
            std::cout << "Link: " << tool.getLink() << "\n";  // Added the display for Tool Link here
            std::cout << "Description: " << tool.getDescription() << "\n";
            std::cout << "-------------------------\n";
        }
    }

    void searchTools(const std::string& keyword) const {
        for (auto const &tool : tools) {
            if (tool.getToolName().find(keyword) != std::string::npos ||
                tool.getLink().find(keyword) != std::string::npos ||  // Added the search capability for Tool Link here
                tool.getDescription().find(keyword) != std::string::npos) {
                std::cout << "Name: " << tool.getToolName() << "\n";
                std::cout << "Category: " << tool.getCategory() << "\n";
                std::cout << "Link: " << tool.getLink() << "\n";  // Displaying the Tool Link in the search results
                std::cout << "Description: " << tool.getDescription() << "\n";
                std::cout << "-------------------------\n";
            }
        }
    }
};

int main() {
    Directory directory;
    std::string command;
    std::cout<<"--------------------------------------------------------------"<<std::endl;
    std::cout<<"\t     Welcome To AI Tool Directory"<<std::endl;
    std::cout<<"\tSearch The Best AI Tool Of Your Needs"<<std::endl;
    std::cout<<"--------------------------------------------------------------"<<std::endl;
    std::cout<<"Choose the options below:"<<std::endl;
    std::cout<<"1. Write 'add' To Add Tool"<<std::endl;
    std::cout<<"2. Write 'list' To View All Tools Listed"<<std::endl;
    std::cout<<"3. Write 'search' To Search Any Tool From Directory"<<std::endl;
    std::cout<<"4. Write 'exit' To Exit From The Program"<<std::endl;
    std::cout<<"\n"<<std::endl;

    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "add") {
            std::string name, category, link, desc;
            std::cin.ignore();  // To clear the newline character from the buffer
            std::cout << "Enter tool name: ";
            std::getline(std::cin, name);
            std::cout << "Enter tool category: ";
            std::getline(std::cin, category);
            std::cout << "Enter tool link: ";  // Added input prompt for Tool Link here
            std::getline(std::cin, link);
            std::cout << "Enter tool description: ";
            std::getline(std::cin, desc);

            Tool tool(name, category, link, desc);
            directory.addTool(tool);
        } else if (command == "list") {
            directory.listTools();
        } else if (command == "search") {
            std::string keyword;
            std::cin.ignore();
            std::cout << "Enter search keyword: ";
            std::getline(std::cin, keyword);
            directory.searchTools(keyword);
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Invalid command. Try 'add', 'list', 'search', or 'exit'." << std::endl;
        }
    }

    return 0;
}
