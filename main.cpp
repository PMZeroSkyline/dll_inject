#include <iostream>

int main() {
    int count = 0;
    while (true)
    {
        int number = 0;
        std::cin >> number;
        count += number;
        std::cout << count << std::endl;
    }
    return 0;
}
