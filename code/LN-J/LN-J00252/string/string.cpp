#include <bits/stdc++.h>
using ll = long long;
constexpr int N = 2e5 + 5;
ll a[N], b[N], st1[N], ed1[N], st2[N], ed2[N];
char c[N], d[N];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ll n; std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i] >> c[i];
        b[n - i + 1] = a[i];
        d[n - i + 1] = c[i];
        st1[i] = ed1[i - 1] + 1;
        ed1[i] = st1[i] + a[i] - 1;
    }
    for (int i = 1; i <= n; i++) {
        st2[i] = ed2[i - 1] + 1;
        ed2[i] = st2[i] + b[i] - 1;
    }
    ll l = 1, r = 1;
    ll ans = 0;
    while (l <= n && r <= n) {
        if (c[l] != d[r]) {
            ll x = std::min(ed1[l], ed2[r]);
            ll y = std::max(st1[l], st2[r]); 
            ans += x - y + 1;
        }
        if (ed1[l] < ed2[r]) l++;
        else if (ed1[l] > ed2[r]) r++;
        else l++, r++; 
    }
    std::cout << ans / 2 << std::endl;
}