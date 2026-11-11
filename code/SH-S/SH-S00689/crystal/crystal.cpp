#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long psum[500005];
bool check(int x, int i, long long m)
{
    return ((i - x + 1) * a[i] - psum[i] + psum[x - 1] <= m);
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        psum[i] = psum[i - 1] + a[i];
    long long cost = 0;
    bool flag = false;
    long long ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int l = 1, r = i, mid;
        while (l < r)
        {
            mid = (l + r) >> 1;
            if (check(mid, i, m))
                r = mid;
            else
                l = mid + 1;
        }
        ans = max(ans, i - r + 1ll);
    }
    cout << ans;
    return 0;
}
