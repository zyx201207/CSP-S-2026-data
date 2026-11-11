#include <bits/stdc++.h>
using namespace std;

inline int calc(int& a, int& b)
{
    if (a == -1) return b;
    if (b == -1) return a;
    return a & b;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> dp(m + 1, -1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= 1; --j)
        {
            dp[j] = max(calc(dp[j - 1], a[i]), dp[j]);
        }
    }

    cout << dp[m] << '\n';

    return 0;
}