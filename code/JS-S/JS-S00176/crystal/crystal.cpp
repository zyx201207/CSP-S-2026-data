#include <bits/stdc++.h>
using namespace std;
const int N = 500010;

int n;
long long m, a[N], sum[N];

inline bool check (int M) {
    for (int i = 1, j = M; j <= n; i++, j++) {
        long long del = sum[j] - sum[i - 1];
        del += a[j] * M;
        if (del <= m)
            return true;
    }
    return false;
}

int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] - a[i];
    int L = 1, R = n + 1;
    while (L + 1 < R) {
        int M = (L + R) >> 1;
        if (check(M))
            L = M;
        else
            R = M;
    }
    cout << L << '\n';
    return 0;
}
