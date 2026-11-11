#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool vis[1 << 20];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, ma = 0;
    cin >> n, m;
    vector<int> nums(n);
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
        ma = max(ma, nums[i]);
        vis[nums[i]] = true;
    }
    if (m == 1) cout << ma;
    else if (m == n) {
        int res = 0;
        for (int i = 0; i < n; i ++) res &= nums[i];
        cout << res;
    }
    return 0;
}