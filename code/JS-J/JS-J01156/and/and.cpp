#include <bits/stdc++.h>

using namespace std;

int n, m;
long long a[200000];
long long ans = 0;
bool skip[200000] = {0};

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int target = 30; target >= 0; --target) {
        int current_sum = 0;

        for (int i = 0; i < n; ++i) {
            if ((!skip[i]) && ((a[i] & (1 << target)) != 0)) {
                ++current_sum;
            }
        }
        if (current_sum >= m) {
            for (int i = 0; i < n; ++i) {
                if ((!skip[i]) && ((a[i] & (1 << target)) == 0)) {
                    skip[i] = 1;
                }
            }
            ans += 1 << target;
        }
    }

    cout << ans;
    return 0;
}
