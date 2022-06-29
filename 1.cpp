#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::string filename = "1.txt";
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Could not open the file - '" << filename << "'" << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;
    file >> line;
    file.close();

    std::vector<char> data;
    std::copy(line.begin(), line.end(), std::back_inserter(data));

    int floor = 0;
    int characterForBasementAt = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == '(')
        {
            floor++;
        }
        else
        {
            floor--;
        }

        // Part 2
        if (floor == -1 and characterForBasementAt == 0)
        {
            characterForBasementAt = i;
            characterForBasementAt++; // Exact vecotr position
        }
    }

    std::cout << "Instructions takes Santa to the floor n: " << floor << std::endl;
    std::cout << "Position of the character for basement is at: "<< characterForBasementAt << std::endl;
    return 0;
}