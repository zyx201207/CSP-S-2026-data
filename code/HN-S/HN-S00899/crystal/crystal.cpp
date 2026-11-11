#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 10;

int n;
ll a[N], m, s[N];

bool Check(int x) {
    for (int l = 1, r = x; r <= n; l++, r++) {
        if (x * a[r] - (s[r] - s[l - 1]) <= m) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        Check(mid) ? l = mid : r = mid - 1;
    }
    cout << l;
    return 0;
}
