#include <iostream>
//#include <string>
#include <unordered_map>
#include <fstream> //for file operations
using namespace std;
int count(char **);
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid syntax!\nType help for more" << std::endl;
        return 0;
    }
    count(argv);
    return 0;
}
int count(char *argv[])
{
    int ch, White_Space = 1, words = 0, lines = 0, characters = 0;
    unordered_map<int,int>freq;//key-element
    std::ifstream myfile(argv[1], std::ios::binary);
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
    std::cout <<"No of words= "<< words << std::endl
              <<"No of lines= "<< lines << std::endl
              <<"No of characters= "<< characters << std::endl;

    myfile.close();
    return 0;
}