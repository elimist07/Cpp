#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#define FILENAME "credentials"
#define TEMPFILE "temp"
using namespace std;

void viewCredentials();
void addCredentials();
void searchCredentials();
void updateCredentials();

string encryptDecrypt(string inpString)
{
    char xorKey = 'P';

    int len = inpString.length();

    for (int i = 0; i < len; i++)
    {
        inpString[i] ^= xorKey;
    }
    return inpString;
}

int main()
{
    int option;
    cout << "\033[2J\033[1;1H"; // clears the screen
    while (1)
    {
        std::cout << "-----PASSWORD MANAGER-----" << std::endl;

        std::cout << "1.View\t2.ADD\t3.Search\t4.Update\t5.Exit\n-->Enter you option: ";
        std::cin >> option;
        if (option == 5)
            break; // exit out of while loop

        switch (option)
        {
        case 1:
            viewCredentials();
            break;
        case 2:
            addCredentials();
            break;
        case 3:
            searchCredentials();
            break;
        case 4:
            updateCredentials();
            break;
        default:
            std::cout << "Error: Not a valid option!\n";
        }
    }

    return 0;
}
void viewCredentials()
{
    cout << "\033[2J\033[1;1H"; // clears the screen
    std::ifstream file(FILENAME);
    if (!file.is_open())
    {
        std::cerr << "ERROR:CANNOT OPEN FILE TO VIEW\n";
        return;
    }

    // Read and display each entry
    std::string line, site, username, password;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::getline(ss, site, '\t');
        std::getline(ss, username, '\t');
        std::getline(ss, password, '\t');
        std::cout << encryptDecrypt(site) << '\t' << encryptDecrypt(username) << '\t' << encryptDecrypt(password) << std::endl;
    }
    file.close();
}

void addCredentials()
{
    std::fstream file(FILENAME, std::ios::app);
    if (!file.is_open())
    {
        std::cerr << "ERROR: CANNOT OPEN FILE TO ADD\n";
        return;
    }
    cout << "\033[2J\033[1;1H"; // clears the screen
    std::string site_name, username, password;
    std::cout << "Enter site name: ";
    std::cin >> site_name;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    file << encryptDecrypt(site_name) << "\t"
         << encryptDecrypt(username) << "\t"
         << encryptDecrypt(password) << std::endl;
    file.close();
}
void searchCredentials()
{
    std::ifstream file(FILENAME);
    if (!file.is_open())
    {
        std::cerr << "ERROR:CANNOT READ FILE TO SEARCH\n";
        return;
    }
    cout << "\033[2J\033[1;1H"; // clears the screen
    std::string search_plain;
    std::cout << "Enter site to search: ";
    std::cin >> search_plain;
    std::string search_encrypted = encryptDecrypt(search_plain);
    std::string site_encrypted, username_encrypted, password_encrypted, line_encrypted;

    while (std::getline(file, line_encrypted))
    {
        std::stringstream ss(line_encrypted);
        std::getline(ss, site_encrypted, '\t');
        std::getline(ss, username_encrypted, '\t');
        std::getline(ss, password_encrypted, '\t');

        if (site_encrypted == search_encrypted)
        {
            std::cout << encryptDecrypt(site_encrypted) << '\t'
                      << encryptDecrypt(username_encrypted) << '\t'
                      << encryptDecrypt(password_encrypted) << std::endl;
            file.close();
            return;
        }
    }
    std::cout << search_plain << " is not in password manager" << std::endl;
    file.close();
}

void updateCredentials()
{
    std::ifstream file(FILENAME);
    if (!file.is_open())
    {
        std::cerr << "ERROR:CANNOT OPEN FILE TO UPDATE\n";
        return;
    }

    std::ofstream temp(TEMPFILE);
    if (!temp.is_open())
    {
        std::cerr << "ERROR READING FILE TO UPDATE\n";
        return;
    }
    cout << "\033[2J\033[1;1H"; // clears the screen
    std::string update_plain;
    std::cout << "Enter the site name whose credentials you want to update: ";
    std::cin >> update_plain;
    std::string update_encrypted = encryptDecrypt(update_plain);

    std::string line_encrypted, site_encrypted, username_encrypted, password_encrypted;
    while (std::getline(file, line_encrypted))
    {

        std::stringstream ss(line_encrypted);
        std::getline(ss, site_encrypted, '\t');
        std::getline(ss, username_encrypted, '\t');
        std::getline(ss, password_encrypted, '\t');

        if (site_encrypted == update_encrypted)
        {
            std::string site_plain, username_plain, password_plain;
            cout << "Enter site new name: ";
            cin >> site_plain;
            site_encrypted = encryptDecrypt(site_plain);

            cout << "Enter new username: ";
            cin >> username_plain;
            username_encrypted = encryptDecrypt(username_plain);

            cout << "Enter new password: ";
            cin >> password_plain;
            password_encrypted = encryptDecrypt(password_plain);
        }
        temp << site_encrypted << "\t"
             << username_encrypted << "\t"
             << password_encrypted << std::endl;
    }
    file.close();
    temp.close();
    remove(FILENAME);
    rename(TEMPFILE, FILENAME);
}