#include <bits/stdc++.h>
using namespace std;
long long c, T;
long long n, d;
vector<long long> a;
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> c >> T;
    while (T--)
    {
        cin >> n >> d;
        a.resize(n + 1);
        for (long long i = 1; i <= n; i++)
            cin >> a[i];
        if (c >= 11 && c <= 12)
        {
            if (d < a[3] - a[1])
            {
                cout << "0\n";
                continue;
            }
            cout << n - (2 * (d / (a[2] - a[1])) - 1) << '\n';
            continue;
        }
        long long ans = 0;
        for (long long u = 1; u <= n; u++)
        {
            for (long long v = u + 2; v <= n; v++)
            {
                vector<pair<long long, long long>> dp(v - u + 2);
                auto getIdx = [&](long long _i)
                {
                    return _i - u + 1;
                };
                dp[getIdx(v)] = {0, 1};
                for (long long i = v - 1; i >= u; i--)
                {
                    long long mnd = 0x7f7f7f7f;
                    long long cnt = 0;
                    for (long long j = i + 1; j <= v; j++)
                    {
                        if (a[j] - a[i] > d)
                            continue;
                        long long nd = dp[getIdx(j)].first + 1;
                        if (nd < mnd)
                        {
                            mnd = nd;
                            cnt = dp[getIdx(j)].second;
                        }
                        else if (nd == mnd)
                            cnt += dp[getIdx(j)].second;
                    }
                    dp[getIdx(i)] = {mnd, cnt};
                }
                // cout << "u,v " << u << ' ' << v << ' ' << dp[getIdx(u)].first << ' ' << dp[getIdx(v)].second << endl;
                if (dp[getIdx(u)].second == 2)
                    ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/