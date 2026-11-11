#include<bits/stdc++.h>
using namespace std;
#define i32 int
#define i64 long long
#define usize size_t
#define Vec vector
#define String string

usize solve(const usize n, const usize m, Vec<i64> &nums) {
    sort(nums.begin(), nums.end());
    usize ans = 0;

    usize left = 0, right = 0;
    usize sum = 0;
    while (right < n) {
        while (nums[right] * (right - left) - sum > m) {
            sum -= nums[left];
            left++;
        }
        ans = max(ans, right - left + 1);
        sum += nums[right];
        right++;
    }

    return ans;
}

i32 main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    usize n, m;
    cin >> n >> m;
    Vec<i64> nums(n);
    for (usize i = 0; i < n; i++) cin >> nums[i];
    cout << solve(n, m, nums);

    fclose(stdin);
    fclose(stdout);
    return 0;
}