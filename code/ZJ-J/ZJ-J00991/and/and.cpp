#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
#define ll long long
#define _for(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
ll a[maxn];
bool vis[20];
// int dfs(int depth, int n, int m, int num)
// {
//     if (depth == m)
//         return n;
//     _for(i, num)
//     {
//         if (vis[i])
//             continue;
//         vis[i] = 1;
//         int x = dfs(depth + 1, n & a[i], m, num);
//         if (i == 0 || n < x)
//         {
//             n = x;
//         }
//         vis[i] = 0;

//         // TODO
//     }
//     return n;
// }
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (m == 1)
    {
        ll maxx = 0;
        _for(i, n)
        {
            cin >> a[i];
            maxx = max(maxx, a[i]);
        }
        cout << maxx << endl;
        return 0;
    }
    if (m == n)
    {
        ll ans;
        cin >> ans;
        _for(i, n - 1)
        {
            cin >> a[i + 1];
            ans &= a[i + 1];
        }
        cout << ans << endl;
        return 0;
    }
    if (m == 2)
    {
        _for(i, n)
        {
            cin >> a[i];
        }
        ll ans = 0;
        _for(i, n)
        {
            _for(j, n)
            {
                if (i == j)
                    continue;
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans << endl;
        return 0;
    }
    // if (n <= 20)
    // {
    //     _for(i, n)
    //     {
    //         cin >> a[i];
    //     }
    //     cout << dfs(0, INT_MAX, m, n) << endl;
    //     return 0;
    // }
    bool sa, sb, sc;
    sa = sb = sc = 1;
    _for(i, n)
    {
        cin >> a[i];
        if (a[i] != i)
            sb = 0;
        if (a[i] >= 4)
            sc = 0;
    }
    if (sc)
    {
        int c1, c2;
        _for(i, n)
        {
            if (a[i] == 1)
                c1++;
            if (a[i] == 2)
                c2++;
            if (a[i] == 3)
                m--;
        }
        if (c2 < m && c1 < m)
        {
            cout << 0 << endl;
            return 0;
        }
        if (c2 < m)
        {
            cout << 1 << endl;
            return 0;
        }
        cout << 2 << endl;
        return 0;
    }
    if (sa)
    {
        sort(a, a + n, greater<ll>());
        ll ans = a[0];
        _for(i, m)
        {
            ans &= a[i];
        }
        cout << ans << endl;
        return 0;
    }
}
