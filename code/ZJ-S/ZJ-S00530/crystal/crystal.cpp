#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define int long long

using std::cin;
using std::cout;
using std::sort;

const int N = 5e5;

int n, m;
int a[N + 10];

bool check(int x)
{
    int sum = 0;
    for (int i = 1; i < x; i++)
        sum += (a[x] - a[i]);
    if (sum <= m)
        return true;
    for (int i = x + 1; i <= n; i++)
    {
        sum -= (a[i] - a[i - x + 1]);
        sum += (x - 1) * (a[i] - a[i - 1]);
        if (sum <= m)
            return true;
    }
    return false;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, r = n;
    while (l + 1 < r)
    {
        // cout << l << ' ' << r << '\n';
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
    return 0;
}