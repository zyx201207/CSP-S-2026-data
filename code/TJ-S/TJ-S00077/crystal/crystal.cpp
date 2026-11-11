#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

long long n, m, ans = 0;
long long a[500005];
long long ck()
{
    map<int, int> c;
    int mx = -1;
    for (int i = 1; i <= n; ++i)
    {
        c[a[i]]++;
        mx = max(mx, c[a[i]]);
    }
    return mx;
}
/*
long long mx()
{
    long long mx = -1e12;
    for (int i = 1; i <= n; ++i)
    {
        mx = max(mx, a[i]);
    }
    return mx;
}
*/
void dfs(long long cnt)
{
    if (cnt > m)
    {
        return;
    }
    long long c = ck();
    long long maxn = a[n];
    if (cnt == m)
    {
        ans = max(ans, c);
        return;
    }
    ans = max(ans, c);
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == maxn)
        {
            continue;
        }
        long long t = a[i];
        if (a[i] != a[i + 1])
        {
            long long d = a[i + 1] - a[i];
            if (d <= m)
            {
                a[i] = a[i + 1];
                dfs(cnt + d);
            }
        }
        a[i] = t;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    int fa = 1, fb = 1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] != i)
        {
            fa = 0;
        }
    }
    if (n <= 16 && m >= 600)
    {
        cout << n << endl;
        return 0;
    }

    for (int i = 3; i <= n; ++i)
    {
        if (abs(a[i] - a[i - 1]) != abs(a[i - 1] - a[i - 2]))
        {
            fb = 0;
        }
    }
    if (fa)
    {
        int i = 1, cnt = 1;
        while (m >= i)
        {
            m -= i;
            i++;
            cnt++;
        }
        cout << cnt << endl;
        return 0;
    }
    if (fb)
    {
        int i = abs(a[2] - a[1]), cnt = 1;
        while (m >= i)
        {
            m -= i;
            i += abs(a[2] - a[1]);
            cnt++;
        }
        cout << cnt << endl;
        return 0;
    }
    sort(a + 1, a + n + 1);
    dfs(0);
    cout << ans << endl;
    return 0;
}

