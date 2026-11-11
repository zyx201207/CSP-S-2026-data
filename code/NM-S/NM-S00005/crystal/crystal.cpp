#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<long long> pre;
long long n, m;
bool check(long long x)
{
    long long min_ = LLONG_MAX;
    for (long long i = 1; i <= n - x + 1; i++)
    {
        min_ = min(min_, a[i + x - 1] * (x - 1) - (pre[i + x - 2] - pre[i - 1]));
    }
    return min_ <= m;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    a.resize(n + 1, 0);
    pre.resize(n + 1, 0);
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (long long i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    long long l = 0, r = m + 1;
    while (l + 1 < r)
    {
        long long mid = ((l + r + 1ll) >> 1ll);
        if (check(mid - 1))
            l = mid;
        else
            r = mid;
    }
    cout << l - 1;
}