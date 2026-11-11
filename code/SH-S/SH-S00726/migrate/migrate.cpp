#include<bits/stdc++.h>
using namespace std;
#define i32 int
#define i64 long long
#define usize size_t
#define Vec vector
#define String string
Vec<i64> nums;
Vec<usize> shortest;
Vec<usize> cnt;
i64 d;

void dfs(usize idx, usize step) {
    if (idx >= nums.size()) return;
    if (shortest[idx] == 1e18) {
        shortest[idx] = step;
        cnt[idx]++;
    }
    else if (shortest[idx] == step) {
        cnt[idx]++;
    }
    for (usize i = nums.size() - 1; i > idx; i--) {
        if (nums[i] - nums[idx] <= d) dfs(i, step + 1);
    }
}
i32 main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    usize c, t;
    cin >> c >> t;
    for (usize time = 0; time < t; time++) {
        usize n;
        cin >> n >> d;
        usize ans = 0;
        nums.resize(n);
        shortest.resize(n);
        cnt.resize(n);
        for (usize i = 0; i < n; i++) {
            cin >> nums[i];
        }
        for (usize i = 0; i < n; i++) {
            for (usize j = 0; j < n; j++) {
                shortest[j] = 1e18;
                cnt[j] = 0;
            }
            dfs(i, 0);
            for (usize j = i + 1; j < n; j++) {
                if (cnt[j] == 2) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}