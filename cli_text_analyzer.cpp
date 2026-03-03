#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> //for sort function
#include <fstream>   //for file operations
#include <cctype>
using namespace std;
void count(const std::string);
void frequency(const std::string);
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid syntax!" << std::endl;
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
    int ch;
    bool white_space = false;
    long int words = 0, lines = 0, characters = 0;

    while ((ch = myfile.get()) != EOF)
    {
        characters++;
        if (static_cast<char>(ch) == '\n')
            lines++;
        if (std::isspace(static_cast<unsigned char>(ch)))
        {
            white_space = false;
        }
        else if (!white_space)
        {
            white_space = true;
            words++;
        }
    }
    std::cout << "No of words= " << words << std::endl
              << "No of lines= " << lines << std::endl
              << "No of characters= " << characters << std::endl;

    myfile.close();
}
void frequency(const std::string user_file)
{
    std::ifstream file(user_file,std::ios::in);
    if (!file.is_open())
    {
        return;
    }

    std::unordered_map<std::string, int> frequency;
    std::string word;

    while (file >> word)
    {
        std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c)
                       { return std::tolower(c) ;});//converts to lower case
        frequency[word]++;
    }


    std::vector<std::pair<std::string, int>> ranked(frequency.begin(), frequency.end()); // copies all key-pair value of ordered map into ranked pair vector
    std::sort(ranked.begin(), ranked.end(), [](const auto &a, const auto &b)
              { return a.second > b.second; }); // sorts in descending order



    std::cout << "Top 3 Frequent Words\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << ranked[i].first << " : " << ranked[i].second << " times" << std::endl;
    }

    
    file.close();
}