#include<bits/stdc++.h>
using namespace std;

long long n, m, ans, a[500005];

bool check(long long x)
{
    unsigned long long res = 0;
    for (int i = 1; i < x; i++)
        res += a[x] - a[i];
    if (res > m)
        return 0;
    return 1;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    long long l = 0, r = n;
    while(l <= r)
    {
        long long mid = (r - l) / 2 + l;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}
