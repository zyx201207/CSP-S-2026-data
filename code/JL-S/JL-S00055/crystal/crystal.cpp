#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long

using namespace std;

const int N = 500010;

int n, m;
int a[N];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0, l = 1, now = 0;
    for (int i = 1; i <= n; i ++ )
    {
        while (l <= i && now > m)
        {
            now -= a[i] - a[l];
            l ++ ;
        }
        now += (a[i + 1] - a[i]) * (i - l + 1);
        ans = max(ans, i - l + 1);
    }
    cout << ans << '\n';

    return 0;
}
