#include <iostream>

class GCDCalculator {
public:
    
    int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int findLCM(int a, int b) {
        return (a * b) / findGCD(a, b); 
    }
};

int main() {
    GCDCalculator calc;
    int num1, num2;

    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    int gcd = calc.findGCD(num1, num2);
    int lcm = calc.findLCM(num1, num2);

    std::cout << "The GCD is: " << gcd << std::endl;
    std::cout << "The LCM is: " << lcm << std::endl;

    return 0;
}
