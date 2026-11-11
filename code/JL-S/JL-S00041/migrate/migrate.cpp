#include<bits/stdc++.h>
#define int long long
const int N = 2e6+10;
using namespace std;
int c, t, n, d, delta, ans;
int xs[N];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        ans = 0;
        if(n == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        cin >> n >> d;
        for(int i=1;i<=n;i++)
        {
            cin >> xs[i];
        }
        delta = xs[2] - xs[1];
        int l = xs[n] - xs[1];
        int y = l % delta;
        int s = l / delta;
        int s0 = s;
        while(s > 0)
        {
            if(y > 0) ans += (s0 - s + 1) * (s + 1)*s / 2;
            y--;
            y = (y + delta) % delta;
            if(y == 0) s--;
        }
        cout << ans << '\n';
    }
    return 0;
}