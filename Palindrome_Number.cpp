#include <vector>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        std::vector<int> nums;

        while(x > 0)
        {
            int res = x % 10;
            x /= 10;
            nums.push_back(res);
        }
        
        int i = 0, j = nums.size() - 1;
        int size = nums.size() / 2;
        while (i <= size && j >= size)
        {
            if (nums[i] != nums[j])
                return false;
            --j;
            ++i;
        }        
        return true;
    }
};

int main()
{
    Solution s;

    s.isPalindrome(121);

    return 0;

}