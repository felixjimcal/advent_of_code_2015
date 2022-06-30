#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main()
{
    std::string filename = "2.txt";
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Could not open the file - '" << filename << "'" << std::endl;
        return EXIT_FAILURE;
    }

    int wrappingPapperNeeded = 0, ribbonNeeded = 0;
    std::string line = "";
    while (std::getline(file, line, '\n'))
    {
        int l = 0, w = 0, h = 0;
        std::istringstream iss(line);
        std::string segment;
        std::vector<int> seglist;
        while (std::getline(iss, segment, 'x'))
        {
            seglist.push_back(std::stoi(segment));
        }
        l = seglist[0];
        w = seglist[1];
        h = seglist[2];
        wrappingPapperNeeded += 2 * (l * w + w * h + h * l) + std::min({l * w, w * h, h * l});

        // Part 2
        ribbonNeeded += std::min({2 * (l + w), 2 * (w + h), 2 * (h + l)}) + l * w * h;
    }
    std::cout << "Wrapping paper needed: " << wrappingPapperNeeded << std::endl;
    std::cout << "Ribbon needed: " << ribbonNeeded << std::endl;

    return 0;
}