#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long> a;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<long long> d(n + 1, 0);
    for (int i = 1; i < n; i++)
        d[i] = a[i + 1] - a[i];
    vector<__int128_t> psd(n + 1, 0);
    for (int i = n - 1; i >= 1; i--)
        psd[i] = psd[i + 1] + d[i];
    vector<__int128_t> pspsd(n + 1, 0);
    for (int i = n - 1; i >= 1; i--)
        pspsd[i] = pspsd[i + 1] + psd[i];
    auto query = [&](int l, int r) -> __int128_t
    {
        return pspsd[l] - pspsd[r + 1] - (__int128_t)(r - l + 1) * psd[r + 1];
    };
    int l = 1, r = 1;
    int ans = 0;
    while (r < n)
    {
        while (l < r && query(l, r) > m)
            l++;
        while (r + 1 < n && query(l, r + 1) <= m)
            r++;
        ans = max(ans, r - l + 2);
        r++;
    }
    cout << ans << endl;
    return 0;
}