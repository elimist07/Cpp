#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Student
{
public:
    char name[100];
    int id;
};
int add_record(const std::string);
int delete_record(std::string);
int search_record(std::string);
int show(const std::string);
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
    return 0;
}
int add_record(const std::string file_name)
{
    std::ofstream user_file(file_name, std::ios::app | std::ios::binary);
    if (!user_file.is_open())
    {
        std::cerr << "Error: Failed to open file" << std::endl;
        return 1;
    }

    Student student;
    std::cout << "Enter Student's name and id: ";
    std::cin >> student.name >> student.id;

    user_file.write(reinterpret_cast<const char *>(&student), sizeof(Student));

    user_file.close();
    return 0;
}

int show(const std::string file_name)
{
    std::ifstream user_file(file_name, std::ios::in | std::ios::binary);
    if (!user_file.is_open())
    {
        std::cerr << "Error: Failed to open file" << std::endl;
        return 1;
    }

    Student student;
    while (user_file.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        std::cout << "Name: " << student.name << std::endl;
        std::cout << "Id: " << student.id << std::endl;
    }

    user_file.close();
    return 0;
}

int delete_record(std::string file_name)
{
    std::ifstream user_file(file_name, std::ios::in);
    if (!user_file.is_open())
    {
        return 1;
    }

    std::string temp = "temp.bin";
    std::ofstream temp_file(temp, std::ios::out);
    if (!temp_file.is_open())
    {
        return 1;
    }
    
    int id;
    Student student;
    std::cout << "Enter record id you want to delete: ";
    std::cin >> id;
    while (user_file.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        if (student.id != id)
            temp_file.write(reinterpret_cast<char *>(&student), sizeof(Student));
    }

    user_file.close();
    temp_file.close();
    if (remove(file_name.c_str()) != 0)
    {
        remove("temp.bin");
        return 1;
    }
    rename("temp.bin", file_name.c_str());

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