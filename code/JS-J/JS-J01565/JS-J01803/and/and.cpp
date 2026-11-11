#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, ans = 0;

string a[200005];

string zhuan(int x)
{
    string s = "";
    while (x != 0)
    {
        s = char(x % 2 + '0') + s;
        x /= 2;
    }
    while (s.size() < 31) s = '0' + s;
    return s;
}

int p(int x)
{
    int mul = 1;
    for (int i = 1; i <= x; i++) mul *= 2;
    return mul;
}

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = zhuan(x);
    }
    for (int i = 0; i < 31; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j][i] == '1') cnt++;
        }
        if (cnt >= m)
        {
            ans += p(31 - i - 1);
            for (int j = 1; j <= n; j++)
            {
                if (a[j][i] == '0') a[j] = "0000000000000000000000000000000";
            }
        }
    }
    cout << ans;
    return 0;
}
