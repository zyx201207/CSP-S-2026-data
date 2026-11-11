#include <bits/stdc++.h>
#define int long long
using namespace std;

int T = 1;
const int N = 2e5 + 10;
int n, m;
int arr[N];
bool flag[N];

void Solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 30; i >= 0; i--) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (flag[j]) continue;
            if ((1 << i) & arr[j]) {
                cnt++;
            }
        }
        if (cnt >= m) {
            for (int j = 1; j <= n; j++) {
                if (flag[j]) continue;
                if (!((1 << i) & arr[j])) {
                    flag[j] = true;
                }
            }
        }
    }
    int ans = INT_MAX, tmp = 0;
    for (int i = 1; i <= n && tmp < m; i++) {
        if (!flag[i]) {
            ans &= arr[i];
            tmp++;
        }
    }
    cout << ans;
}

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (T--) {
        Solve();
    }
    return 0;
}
