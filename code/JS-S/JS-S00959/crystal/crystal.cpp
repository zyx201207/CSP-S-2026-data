#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 7;
int n, m, a[N], ans;

bool check(int num)
{
    int now = 0;
    //cout << num << endl;
    for (int i = 1; i <= num; ++i)
        now += a[num] - a[i];
    for (int i = 1; i <= n - num + 1; ++i)
    {
        if (now <= m)
            return true;
        if (i == n - num + 1)
            break;
        now += (a[i + num] - a[i + num - 1]) * (num - 1);
        now -= a[i + num - 1] - a[i];
    }
    return false;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; --i)
        a[i] -= a[1];
    int l = 1, r = n, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}