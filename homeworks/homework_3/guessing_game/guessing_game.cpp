#include <iostream>
#include <random>

int main() {
  int long smallest_number{}, largest_number{}, user_guess{}, guess_count{1};
  std::random_device random_device;
  std::mt19937 random_engine{random_device()};
  // print welcome message
  std::cout << "Welcome to the GUESSING GAME!" << std::endl;
  std::cout << "I will generate a number and you will guess it!" << std::endl;

  // get a smallest number from user
  std::cout << "Please provide the smallest number:" << std::endl;
  std::cin >> smallest_number;

  // get a largest number from user
  std::cout << "Please provide the largest number:" << std::endl;
  std::cin >> largest_number;

  // generage a random number between the smallest number and largest number
  std::uniform_int_distribution<int long> distribution{smallest_number,
                                                       largest_number};
  auto answer = distribution(random_engine);
  std::cout << "I've generated a number. Try to guess it!" << std::endl;

  // start guessing game with user
  while (true) {
    std::cout << "Please provide the next guess: ";
    std::cin >> user_guess;
    if (user_guess < answer) {
      std::cout << "Your number is too small. Try again!" << std::endl;
      guess_count += 1;
      continue;
    } else if (user_guess > answer) {
      std::cout << "Your number is too big. Try again!" << std::endl;
      guess_count += 1;
      continue;
    }
    // end game as guess is correct
    std::cout << "You've done it! You guessed the number " << answer << " in "
              << guess_count << " guesses!" << std::endl;
    break;
  }

  return 0;
}