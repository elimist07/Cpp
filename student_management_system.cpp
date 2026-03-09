#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class Student
{
public:
    char name[100];
    int id;
    /*operator overloading for < using id for comparison.
    The operator < is a member function of Student.
    Member functions have direct access to the class's own members(id,name),
    without needing to specify which object,
    because they are already inside that object's context.
    */
    bool operator<(const Student &other) const
    {
        return id < other.id;
    }
};
int add_record(const std::string);
int delete_record(std::string);
int search_record(std::string);
int show(const std::string);
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
            if (add_record(file_name))
                return 0;
            break;
        }
        case 2:
        {
            if (delete_record(file_name))
                return 0;
            break;
        }
        case 3:
        {
            if (search_record(file_name))
                return 0;
            break;
        }
        case 4:
        {
            if (show(file_name))
                return 0;
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

int delete_record(std::string file_name)
{
    std::ifstream user_file(file_name, std::ios::in | std::ios::binary);
    if (!user_file.is_open())
    {
        std::cerr << "Error: Failed to open file" << std::endl;
        return 1;
    }

    std::string temp = "temp.bin";
    std::ofstream temp_file(temp, std::ios::out | std::ios::binary);
    if (!temp_file.is_open())
    {
        std::cerr << "Error: Failed to open file" << std::endl;
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
    std::ifstream user_file(file_name, std::ios::in | std::ios::binary);
    if (!user_file.is_open())
    {
        std::cerr << "Error: Failed to open file" << std::endl;
        return 1;
    }
    int id;
    std::cout << "Enter Id you want to search: ";
    std::cin >> id;
    Student student;
    while (user_file.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        if (student.id == id)
        {
            std::cout << "ID FOUND" << std::endl;
            std::cout << "Id: " << student.id << "\nName: " << student.name << std::endl;
            user_file.close();
            return 0;
        }
    }
    std::cout<<"Id does not exist"<<std::endl;
    user_file.close();
    return 0;
}

int show(std::string file_name)
{
    std::ifstream user_file(file_name, std::ios::in | std::ios::binary);
    if (!user_file.is_open())
    {
        std::cerr << "Error: Failed to open file" << std::endl;
        return 1;
    }
    // does sorting first and then displays data
    std::vector<Student> student;
    Student temp;
    while (user_file.read(reinterpret_cast<char *>(&temp), sizeof(Student)))
    {
        student.push_back(temp);
    }

    std::sort(student.begin(), student.end());
    for (auto &p : student)
    {
        std::cout << "Id: " << p.id << std::endl;
        std::cout << "Name: " << p.name << std::endl;
    }

    user_file.close();
    return 0;
}
