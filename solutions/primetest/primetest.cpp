#include <iostream>
#include <math.h>

bool isPrime(int number) {
    if(number <= 1) {
        return false;
    }
    if(number == 2) {
        return true;
    }
    for(int i=2; i<=sqrt(number); i++) {
        if(number%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    std::cin >> number;
    std::cout << "is number " << number << " prime? " << isPrime(number);
}