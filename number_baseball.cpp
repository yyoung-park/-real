#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

void generateRandomNumber(std::vector<int>& number) {
    srand(time(0));
    while (number.size() < 3) {
        int digit = rand() % 10;
        if (std::find(number.begin(), number.end(), digit) == number.end()) {
            number.push_back(digit);
        }
    }
}

void getUserInput(std::vector<int>& guess) {
    int input;
    std::cout << "세 자리 숫자를 입력하세요 (각 자리 숫자는 중복되지 않아야 합니다): ";
    std::cin >> input;
    guess.clear();
    while (input > 0) {
        guess.insert(guess.begin(), input % 10);
        input /= 10;
    }
}

void compareNumbers(const std::vector<int>& number, const std::vector<int>& guess, int& strikes, int& balls) {
    strikes = 0;
    balls = 0;
    for (int i = 0; i < 3; ++i) {
        if (guess[i] == number[i]) {
            strikes++;
        } else if (std::find(number.begin(), number.end(), guess[i]) != number.end()) {
            balls++;
        }
    }
}

int main() {
    std::vector<int> number;
    std::vector<int> guess;
    int strikes = 0, balls = 0;

    generateRandomNumber(number);

    while (strikes < 3) {
        getUserInput(guess);
        compareNumbers(number, guess, strikes, balls);
        std::cout << "스트라이크: " << strikes << ", 볼: " << balls << std::endl;
    }

    std::cout << "축하합니다! 숫자를 맞추셨습니다!" << std::endl;
    return 0;
}