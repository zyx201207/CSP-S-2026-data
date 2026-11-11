#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    if(c == 11 || c == 12)
    {
        while(t--)
        {
            int n, d;
            cin >> n >> d;
            for(int i = 1; i <= n; i++)
                cin >> a[i];
            if(n == 1)
            {
                cout << 0 << endl;
            }
            else
            {
                int dis = a[n] - a[n - 1];
                int cnt = d / dis;
                if(cnt < 2) cout << 0 << endl;
                else
                {
                    int sum = cnt * 2;
                    int ans = n - sum + 1;
                    if(ans <= 0) cout << 0 << endl;
                    else if(ans >= n) cout << 0 << endl;
                    else cout << ans << endl;
                }
            }
        }
    }
    return 0;
}

