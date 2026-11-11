#include <bits/stdc++.h>
using namespace std;

int n, m, a[200005], maxn, flag6 = 1, t, ans, cnt;
bool f[200005][35], vis[100005], flag[35];

void d(int x, int y)
{
    int x12 = x;
    int cnt = 0;
    while (x12)
    {
        f[y][cnt] = x12 % 2;
        x12 /= 2;
        cnt++;
    }
}
bool cmp(int x, int y)
{
    return x > y;
}

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == 1) t = a[i];
        else t = t & a[i];
        maxn = max(maxn, a[i]);
        if (a[i] & (a[i - 1])) flag6 = 0;
    }
    memset(flag, 1, sizeof flag);
    sort(a + 1, a + n + 1, cmp);
    if (m == 1)
    {
        cout << maxn;
        return 0;
    }
    if (m == n)
    {
        cout << t;
        return 0;
    }
    if (m == 2)
    {
        int s = -1e9;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++) s = max(s, a[i] & a[j]);
        }
        cout << s;
        return 0;
    }
    if (flag6)
    {
        cout << a[m];
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        d(a[i], i);
    }
    for (int i = 30; i >= 0; i--)
    {
        if (!flag[i]) continue;
       int flag1 = 0;
       //cout << flag1<< " ";
       for (int j = 1; j <= n; j++) flag1 += f[j][i];

       if (flag1 < m)
       {
           flag[i] = 0;
           continue;
       }
       flag1 = 0;
        for (int j = 1; j <= n; j++)
        {
            if (f[j][i])
            {
                flag1++;
                if (!vis[j]) cnt++;
                vis[j] = 1;
                int x = a[j];
                int s = 0;
                while (x)
                {
                    if (x % 2 == 0)
                    {
                        flag[s] = 0;
                    }
                    x /= 2;
                    s++;
                }
            }
        }
        if (!flag1) flag[i] = 0;
    }
    for (int i = 30; i >= 0; i--) ans += flag[i] * pow(2, i);
    cout << ans;
    return 0;
}
