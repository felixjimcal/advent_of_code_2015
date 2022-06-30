#include <iostream>
#include <fstream>
#include <vector>
#include <set>

int main()
{
    std::string filename = "3.txt";
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
    

    struct Santa
    {
        int x = 0;
        int y = 0;
        std::set<std::pair<int, int>> visitedHouses;
        
        Santa()
        {
            visitedHouses.insert(std::make_pair(x, y));
        }

        std::pair<int, int> move(char direction)
        {
            if (direction == '^')
            {
                x++;
            }
            else if (direction == 'v')
            {
                x--;
            }
            else if (direction == '<')
            {
                y--;
            }
            else if (direction == '>')
            {
                y++;
            }
            return std::make_pair(x, y);
        }
    } santas, roboSantas;

    bool santasTurn = true;
    for (int i = 0; i < data.size(); i++)
    {
        if (santasTurn)
        {
            santas.visitedHouses.insert(santas.move(data[i]));
        }
        else
        {
            roboSantas.visitedHouses.insert(roboSantas.move(data[i]));
        }
       santasTurn = !santasTurn;
    }

    std::set<std::pair<int, int>> houses (santas.visitedHouses.begin(), santas.visitedHouses.end());
    houses.insert(roboSantas.visitedHouses.begin(), roboSantas.visitedHouses.end());
    std::cout << "Number of houses visited: " << houses.size() << std::endl;

    return EXIT_SUCCESS;
}