#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

enum Status { ON, OFF, TOGGLE };
struct Orders {
    Status status;
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
} orders;

void SplitWords(std::string line, Orders &orders) {
    std::istringstream ss(line);
    std::string word;
    while (ss >> word) {
        int index = word.find(",");
        if (index != std::string::npos) {
            int x = std::stoi(word.substr(0, index));
            int y = std::stoi(word.substr(index + 1, word.size() - index));

            if (orders.x1 == -1) {
                orders.x1 = x;
                orders.y1 = y;
            } else {
                orders.x2 = x;
                orders.y2 = y;
            }
        }
    }
}

int main() {
    std::string filename = "6.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Could not open the file - '" << filename << "'" << std::endl;
        return EXIT_FAILURE;
    }

    struct Orders orders;
    std::string line = "";
    std::vector<Orders> allOrders;
    while (std::getline(file, line, '\n')) {
        if (line.find("toggle") != std::string::npos) {
            orders.status = TOGGLE;
            SplitWords(line, orders);
        } else if (line.find("off") != std::string::npos) {
            orders.status = OFF;
            SplitWords(line, orders);
        } else {
            orders.status = ON;
            SplitWords(line, orders);
        }
        allOrders.push_back(orders);
    }

    struct Light{
        Status status = OFF;
    };

    Light allLights[0][0];
    for (auto order : allOrders) {
        for (int j = order.x1; j < order.x2; j++) {
            for (int h = order.y1; h < order.y2; h++) {
                if (order.status == TOGGLE) {
                    allLights[j][h].status = ( allLights[j][h].status == ON) ? OFF : ON;
                }else if (order.status == ON) {
                    allLights[j][h].status = ON;
                } else if (order.status == OFF) {
                    allLights[j][h].status = OFF;
                }
            }
        }
    }
    // std::cout << 2 * (lightsOnX + lightsOnY) << std::endl;

    return EXIT_SUCCESS;
}
