#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
bitset<35> mp[N];
signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[i][0] = 1;
        int cnt = 0;
        while (x)
        {
            cnt++;
            mp[i][cnt] = x & 1;
            x >>= 1;
        }
    }
    int ans = 0;
    for (int i = 31; i >= 1; i--)
    {
        int num = 0;
        for (int j = 1; j <= n; j++)
            num += mp[j][i] * mp[j][0];
        if (num >= m)
        {
            for (int j = 1; j <= n; j++)
                if (mp[j][i] == 0)
                    mp[j][0] = 0;
            ans += (1ll << (i - 1));
        }
    }
    cout << ans;
    return 0;
}