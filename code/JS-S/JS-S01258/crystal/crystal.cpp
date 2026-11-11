#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a[500010];
long long s[500010];

long long calc(int l, int r) {
    return (r - l + 1) * a[r] - (s[r] - s[l - 1]);
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int L = i, R = n + 1;
        for (; L + 1 < R; ) {
            int M = (L + R) >> 1;
            if (calc(i, M) <= m)
                L = M;
            else
                R = M;
        }
        ans = max(ans, L - i + 1);
    }
    cout << ans << "\n";
    return 0;
}
