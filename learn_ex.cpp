#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

int main()
{
    srand(time(NULL));

    std::cout << "A Game to learn exponents of 2. Type exit to exit\n";

    int score = 0;
    int max_ex_num = 15;

    std::cout << "Maximal exponent: ";
    std::cin >> max_ex_num;

    int zweier_potenzen[max_ex_num];
    for(int i = 0; i < max_ex_num + 1; i++)
    {
        zweier_potenzen[i] = pow(2, i);
    }

    int random_ex = rand() % max_ex_num + 1;
    std::string input = "";

    while (true)
    {
        if (rand() % 2 == 0)
        {
            std::cout << "2^" << random_ex << "=";
            std::cin >> input;
            if (input == "exit")
                break;

            if (std::stoi(input) == pow(2, random_ex))
            {
                score++;
                random_ex = rand() % max_ex_num + 1;
                std::cout << "Correct!!!" << "\n";
            }
            else
            {
                std::cout << "Bitch!!!" << "\n";
            }
        }
        else
        {
            std::cout << zweier_potenzen[random_ex] << "=2^";
            std::cin >> input;
            if (input == "exit")
                break;

            if (pow(2, std::stoi(input)) == zweier_potenzen[random_ex])
            {
                score++;
                random_ex = rand() % max_ex_num + 1;
                std::cout << "Correct!!!" << "\n";
            }
            else
            {
                std::cout << "Bitch!!!" << "\n";
            }
        }
    }

    std::cout << "Your score is " << score << "\n";
}
