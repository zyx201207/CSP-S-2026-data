#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, cur, ans = 1, lst;
int a[N], p[N], sum[N]; // p[i] : During 1~i, we need to spend p[i]
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if(n == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
    if(n == 2)
    {
        cout << (m < a[2] - a[1] ? 1 : 2) << '\n';
        return 0;
    }
    cur = a[2] - a[1];
    // cur : how much you spend now
    p[1] = 0;
    p[2] = a[2] - a[1];
    for(int i = 3; i <= n; i++)
    {
        cur = cur + (a[i] - a[i - 1]) * (i - 1);
        sum[i] = sum[i - 1] + (a[i] - a[i - 1]);
        p[i] = cur;
    }
    for(int l = 1, r = 1; l <= n && r <= n; r++)
    {
        lst += (l - 1) * (a[r] - a[r - 1]);
        while(p[r] - lst > m && l < r)
        {
            lst += a[r] - a[l];
            // cout << lst << ' ';
            l++;
        }
        // cout << l << ' ' << r << ' ' << p[r] - lst << '\n';
        // cout << l << ' ' << r << ' ' << p[l] << ' ' << p[r] << '\n';
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
