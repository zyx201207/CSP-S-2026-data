#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<long long, char>> a;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    int l = 1, r = n;
    long long ans = 0;
    while (l < r)
    {
        long long dt = min(a[l].first, a[r].first);
        if (a[l].second != a[r].second)
            ans += dt;
        a[l].first -= dt;
        a[r].first -= dt;
        if (a[l].first == 0)
            l++;
        if (a[r].first == 0)
            r--;
    }
    cout << ans << endl;
    return 0;
}