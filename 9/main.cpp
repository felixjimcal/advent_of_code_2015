#include <algorithm>
#include <fstream>
#include <iostream>
#include <utility>
#include <map>
#include <set>
#include <vector>

int main() {
  std::fstream fcin;
  std::string from, to, distance, temp;

  fcin.open("9.txt", std::ios::in);

  std::map<std::set<std::string>, int> distances;
  std::set<std::string> places;
  while (!fcin.eof()) {
    fcin >> from;
    fcin >> temp;
    fcin >> to;
    fcin >> temp;
    fcin >> distance;
    distances.insert({{from, to}, std::stoi(distance)});
    places.insert(from);
    places.insert(to);
  }

  int maxNumCombinations = places.size();

  std::set<std::vector<std::string>> combinations;

  std::vector<std::string> combos;
  std::copy(places.begin(), places.end(), std::back_inserter(combos));
  for (int i = 0; i < maxNumCombinations; i++) {
    std::rotate(combos.begin(), combos.begin() + 1, combos.end());
    combinations.insert(combinations.begin(), combos);
  }

  int lowestDistance = 0;
  for(const auto &combo : combinations) {
      std::set<std::string> container;
      for(int i = 0; i < combo.size(); i++){
          container.insert(combo[i]);
          const bool is_in = distances.find(container) != distances.end();
          if(is_in){
              lowestDistance += distances.find(container)->second;
          } else {
              std::vector<std::string> combis;
              std::copy(container.begin(), container.end(), std::back_inserter(combis));
              std::rotate(combis.begin(), combis.begin() + 1, combis.end());
              std::set<std::string> contains(combis.begin(), combis.end());
              if(distances.find(contains) != distances.end()){
                  lowestDistance += distances.find(contains)->second;
              }
          }
      }
  }

  return 0;
}
