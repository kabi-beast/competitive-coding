#include <iostream>
#include <math.h>

int f[100], expo[100], len;

void getPrimeFactors(int number) {
    int d = 2;
    while(number > 1 && d<=sqrt(number)) {
        int k = 0;
        while(number%d==0) {
            number /= d;
            k++;
        }
        if(k>0) {
            f[len] = d;
            expo[len] = k;
            len++;
        }
        d++;
    }
    if(number>1) {
        f[len] = number;
        expo[len] = 1;
        len++;
    }
}

int main() {
    int number;
    std::cin >> number;
    getPrimeFactors(number);
    for(int i=0; i<len; i++) {
        std::cout << f[i] << " " << expo[i] << std::endl;
    }
}