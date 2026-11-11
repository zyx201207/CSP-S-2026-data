#include<bits/stdc++.h>
#define int long long
using namespace std;
/* Define & Const */
const int N = 2e6 + 10;
/* Struct */

/* Variables */
int c, t;
int n, d;
int a[N];
/* Functions */

/* Main */
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (c == 11 || c == 12)
        {
            int x = max(2 * (d / (a[1] - a[0])) - 1, 0LL);
            //cout << x << "\n";
            int ans = 0;
            if (x > 0)
                ans = n - x;
            else
                ans = 0;
            cout << max(ans, 0LL) << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
}