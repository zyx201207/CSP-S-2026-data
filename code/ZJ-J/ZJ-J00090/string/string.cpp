#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, a[200010];
char s[200010];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %c", &a[i], &s[i]);
    vector<pair<ll, char>> m;
    for (int i = 1; i <= n; i++)
        if (m.empty())
            m.push_back({a[i], s[i]});
        else
            if (s[i] == m.back().second)
                m.back().first += a[i];
            else
                m.push_back({a[i], s[i]});
    int l = 0, r = m.size();
    ll ans = 0;
    for (; l < r; ) {
        ll t = min(m[l].first, m[r].first);
        m[l].first -= t;
        m[r].first -= t;
        if (m[l].second != m[r].second)
            ans += t;
        if (m[l].first == 0)
            l++;
        if (m[r].first == 0)
            r--;
    }
    printf("%lld\n", ans);
    return 0;
}
