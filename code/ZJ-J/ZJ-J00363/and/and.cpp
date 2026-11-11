#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    size_t n, m;
    std::cin >> n >> m;
    std::vector<size_t> nums(n + 1);
    for(auto& elem : nums) std::cin >> elem;
    size_t left = 0, right = m - 1, ans = nums[left], res = 0;
    for(;right < nums.size() - 1;) {
        for(size_t i = left; i <= right; i++) ans &= nums[i];
        res = std::max(res, ans);
        left++;
        ans = nums[left];
        right++;
    }
    std::cout << res;
}
