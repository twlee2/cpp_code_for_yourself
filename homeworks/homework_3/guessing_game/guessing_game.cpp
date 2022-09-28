#include <iostream>
#include <random>

void welcome_message() {
  std::cout << "Welcome to the GUESSING GAME!" << std::endl;
  std::cout << "I will generate a number and you will guess it!" << std::endl;
}

int long random_number_generation() {
  int long smallest_number{}, largest_number{};
  std::random_device random_device;
  std::mt19937 random_engine{random_device()};

  std::cout << "Please provide the smallest number: " << std::endl;
  std::cin >> smallest_number;

  std::cout << "Please provide the largest number: " << std::endl;
  std::cin >> largest_number;

  std::uniform_int_distribution<int long> distribution{smallest_number,
                                                       largest_number};
  std::cout << "I've generated a number. Try to guess it!" << std::endl;
  return distribution(random_engine);
}

int long guess_from_user() {
  int long user_guess{};
  std::cout << "Please provide the next guess: ";
  std::cin >> user_guess;
  return user_guess;
}

void guessing_game() {
  int guess_count{1};
  welcome_message();
  int long answer = random_number_generation();
  auto user_guess = guess_from_user();

  while (true) {
    if (user_guess < answer) {
      std::cout << "Your number is too small. Try again!" << std::endl;
      guess_count += 1;
      continue;
    } else if (user_guess > answer) {
      std::cout << "Your number is too big. Try again!" << std::endl;
      guess_count += 1;
      continue;
    }

    std::cout << "You've done it! You guessed the number " << answer << " in "
              << guess_count << " guesses!" << std::endl;
    break;
  }
}

int main() {
  guessing_game();

  return 0;
}