#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;

const long long M = 1e18, A = 1e12;

int n;

long long a[N + 5], s[N + 5], m;

bool check(int x) {
    for (int l = 1, r = x; r <= n; l++, r++)
        if (a[r] * x - (s[r] - s[l - 1]) <= m)
            return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int l = 1, r = n, mid;
    while (l <= r) {
        mid = l + r >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l - 1 << '\n';
    return 0;
}
