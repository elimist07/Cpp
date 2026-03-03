#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Student
{
public:
    std::string name;
    int id;
};
int add_record(std::string);
int delete_record(std::string);
int search_record(std::string);
int show(std::string);
int sort();
int main()
{
    std::string file_name;
    std::cout << "Enter your file name: ";
    std::cin >> file_name;
    int choice;
    while (1)
    {
        std::cout << "\n1.Add Student\n2.Delete Student\n3.Search Student\n4.Show data\nEnter your choice(0 to exit): ";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
        {
            add_record(file_name);
            break;
        }
        case 2:
        {
            delete_record(file_name);
            break;
        }
        case 3:
        {
            search_record(file_name);
            break;
        }
        case 4:
        {
            show(file_name);
            break;
        }
        default:
        {
            std::cout << "\nInvalid choice!" << std::endl;
        }
        }
    }
    // std::vector<Student> student(1);
    // student[0].name = "Henry";
    // student[0].id = 12;
    // std::cout << "Name: " << student[0].name << "\nId: " << student[0].id << std::endl;
    return 0;
}
int add_record(std::string file_name)
{
    std::ofstream user_file(file_name, std::ios::app);
    if (!user_file.is_open())
    {
        std::cerr << "Error: Failed to open file" << std::endl;
        return 0;
    }
    std::vector<Student> student(1);
    std::cout << "Enter Student's name and id: ";
    std::cin >> student[0].name >> student[0].id;
    user_file << student[0].name<<"\t" << student[0].id << std::endl;
    user_file.close();
    return 0;
}

int show(std::string file_name)
{
    std::ifstream user_file(file_name, std::ios::in);
    if (!user_file.is_open())
    {
        std::cerr << "Error: Failed to open file" << std::endl;
        return 0;
    }
    std::string word;
    while (getline(user_file,word))
    {
        std::cout << word<<std::endl;
    }
    user_file.close();
    return 0;
}

int delete_record(std::string file_name)
{
    return 0;
}

int search_record(std::string file_name)
{
    return 0;
}

int sort()
{
    return 0;
}