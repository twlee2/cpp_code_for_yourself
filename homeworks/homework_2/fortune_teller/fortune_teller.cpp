#include <array>
#include <iostream>
#include <map>
#include <string>

namespace {
std::map<std::string, std::string> season_to_noun{
    {"spring", "STL guru"},
    {"summer", "C++ expert"},
    {"autumn", "coding beast"},
    {"winter", "software design hero"}};
}

void welcome_message() {
  std::cout << "Welcome to the fortune teller program!" << std::endl;
}
void get_user_name(std::string &name) {
  std::cout << "Please enter your name:" << std::endl;
  std::cin >> name;
}
void get_time_of_year_user_born(std::string &season) {
  std::cout << "Please enter the time of year when you were born:" << std::endl;
  std::cout << "(pick from 'spring', 'summer', 'autumn', 'winter')"
            << std::endl;

  std::cin >> season;
}
void get_adjectives(std::array<std::string, 2> &adj) {
  std::cout << "Please enter an adjective:" << std::endl;
  std::cin >> adj[0];
  std::cout << "Please enter another adjective:" << std::endl;
  std::cin >> adj[1];
}

void tell_fortune(const std::string &user_name,
                  const std::array<std::string, 2> &adj,
                  const std::string &season) {
  int adj_idx = user_name.size() % adj.size();

  std::array<std::string, 3> ending{"eats UB for breakfast",
                                    "finds errors quicker than the compiler",
                                    "is not afraid of C++ error messages"};
  int ending_idx = user_name.size() % ending.size();
  std::cout << "\nHere is your description:" << std::endl;
  std::cout << user_name << ", "
            << "the " << adj[adj_idx] << " " << season_to_noun[season] << " "
            << "that " << ending[ending_idx] << std::endl;
}

void fortune_teller() {
  std::string user_name, season;
  std::array<std::string, 2> adjectives{};
  welcome_message();
  get_user_name(user_name);
  get_time_of_year_user_born(season);
  get_adjectives(adjectives);
  tell_fortune(user_name, adjectives, season);
}

int main() {
  fortune_teller();

  return 0;
}