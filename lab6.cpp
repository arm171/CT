#include <iostream>
#include <vector>

int findMissing(const std::vector<int>& nums, int limit) {
    
    int totalSum = limit * (limit + 1) / 2;

    
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }

    
    return totalSum - sum;
}

int main() {
    int limit;
    std::cout << "Enter the maximum number: ";
    std::cin >> limit;

    std::vector<int> nums;
    std::cout << "Enter " << (limit - 1) << " numbers between 1 and " << limit << ":\n";
    
    for (int i = 0; i < limit - 1; ) { 
        int num;
        std::cin >> num;

        
        if (num < 1 || num > limit) {
            std::cout << "Invalid input: " << num << ". Please enter a number within the range (1-" << limit << ").\n";
        } else {
            nums.push_back(num);
            i++; 
        }
    }

    int missing = findMissing(nums, limit);
    std::cout << "The missing number is: " << missing << std::endl;

    return 0;
}
