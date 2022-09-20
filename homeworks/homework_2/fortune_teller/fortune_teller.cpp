#include <array>
#include <iostream>
#include <map>
#include <string>

int main() {
  using std::string_literals::operator""s;

  std::string name{};

  std::map<std::string, std::string> season_to_noun{
      {"spring"s, "STL guru"s},
      {"summer"s, "C++ expert"s},
      {"autumn"s, "coding beast"s},
      {"winter"s, "software design hero"s}};

  std::string season{};

  std::array<std::string, 2> adjectives{};

  std::cout << "Welcome to the fortune teller program!" << std::endl;

  std::cout << "Please enter your name:" << std::endl;

  std::cin >> name;

  std::cout << "Please enter the time of year when you were born:" << std::endl;
  std::cout << "(pick from 'spring', 'summer', 'autumn', 'winter')"
            << std::endl;

  std::cin >> season;

  std::cout << "Please enter an adjective:" << std::endl;
  std::cin >> adjectives[0];
  std::cout << "Please enter another adjective:" << std::endl;
  std::cin >> adjectives[1];

  int adj_idx = name.size() % adjectives.size();

  std::array<std::string, 3> ending{"eats UB for breakfast",
                                    "finds errors quicker than the compiler",
                                    "is not afraid of C++ error messages"};
  int ending_idx = name.size() % ending.size();
  std::cout << "\nHere is your description:" << std::endl;
  std::cout << name << ", "
            << "the " << adjectives[adj_idx] << " " << season_to_noun[season]
            << " "
            << "that " << ending[ending_idx] << std::endl;

  return 0;
}