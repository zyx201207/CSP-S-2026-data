#include <bits/stdc++.h>
using namespace std;

#define int long long

int ls[500001];
int s[500001];
int n, m;
int now_max = 0;

int check(int goal) {
    for (int i = goal; i <= n; i++) {
        if (ls[i] * goal - s[i] + s[i - goal] <= m) return 1;
    }
    return 0;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ls[i];
    }
    sort(ls + 1, ls + 1 + n);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + ls[i];
    }
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans;
}
