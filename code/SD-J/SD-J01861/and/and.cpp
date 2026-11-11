#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[200010];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if ((a[j] & ans) == ans && (a[j] & (1 << i))) {
                cnt++;
            }
        }
        if (cnt >= m) {
            ans |= (1 << i);
        }
    }
    cout << ans;
    return 0;
}
