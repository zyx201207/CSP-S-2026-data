// Darkworldmystery 2023 ~ 2027
#include<bits/stdc++.h>

using namespace std;
using LL = long long;

const LL kMaxN = 5e5 + 5;

LL n, m, a[kMaxN], sum[kMaxN], ret = 1;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for(LL i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(LL i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * (i - 1);
    for(LL i = 2; i <= n; i++)
        for(LL j = i - ret; j >= 1; j--)
        {
            LL cost = sum[i] - sum[j] - (a[i] - a[j]) * (j - 1);
            (cost <= m) && (ret = max(ret, i - j + 1));
            if(cost > m)
                break;
        }
    cout << ret << "\n";
    return 0;
}