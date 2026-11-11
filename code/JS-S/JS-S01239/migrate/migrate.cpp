#include<bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN = 2e6 + 5;

int a[MAXN], b[MAXN];

void solve1()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i] - a[i - 1];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int cnt = 0, tot = 0;
            for (int k = j + 1; k < i; k++)
            {
                if (a[k + 1] - a[k - 1] <= d)
                    cnt++;
            }
            for (int k = j + 1; k < i - 1; k++)
            {
                if (a[k + 2] - a[k - 1] <= d)
                    tot++;
            }
            for (int k = j + 1; k <= i; k++)
                if (a[k] - a[k - 1] > d)
                    cnt = 0;
            if (cnt == 2 && tot == 0)
                ans++;
        }
    }
    cout << ans << "\n";
}

void solve2()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 3)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}

void solve3()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << 0 << "\n";
        return;
    }
    int dd = a[2] - a[1];
    if (dd > d)
    {
        cout << 0 << "\n";
        return;
    }
    if (2 * dd <= d)
    {
        cout << n - 2 << "\n";
        return;
    }
    cout << 0 << "\n";
}

signed main()
{
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie (0);
    int c, T;
    cin >> c >> T;
    while (T--)
    {
        if (13 <= c && c <= 14)
            solve2();
        else if (11 <= c && c <= 12)
            solve3();
        else
            solve1();
    }
    return 0;
}
