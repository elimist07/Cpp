#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream> //for file operations
using namespace std;
void count(const std::string);
void frequency(const std::string);
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid syntax!\nType help for more" << std::endl;
        return 0;
    }
    const std::string user_file = argv[1];
    count(user_file);
    frequency(user_file);
    return 0;
}
void count(const std::string user_file)
{
    std::ifstream myfile(user_file, std::ios::binary);
    if (!myfile.is_open())
    {
        cerr << "Error:Cannot open file" << endl;
        return;
    }
    long int ch, White_Space = 1, words = 0, lines = 0, characters = 0;

    while ((ch = myfile.get()) != EOF)
    {
        characters++;
        if (static_cast<char>(ch) == '\n')
            lines++;
        if (White_Space && !isspace(ch))
        {
            White_Space = 0;
            words++;
        }
        else if (!White_Space && isspace(ch))
        {
            White_Space = 1;
        }
    }
    std::cout << "No of words= " << words << std::endl
              << "No of lines= " << lines << std::endl
              << "No of characters= " << characters << std::endl;

    myfile.close();
}
void frequency(const std::string user_file)
{
    std::fstream file;
    file.open(user_file.c_str());
    if (!file.is_open())
        return;
    std::unordered_map<std::string, int> frequency;
    std::string word;
    while (file >> word)
    {
        frequency[word]++;
    }
    file.close();
}