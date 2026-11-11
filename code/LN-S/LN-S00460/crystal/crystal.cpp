

// g++ crystal.cpp -o crystal
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
ll n, m, a[N], d[N];
int ans, l, r;
bool fA;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    fA = true;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        d[i] = a[i] - a[i - 1];
        if (i > 1 && d[i] != d[i - 1])
            fA = false;
    }
    if (fA) {
        int lo = 1, hi = n + 1;
        while (lo + 1 != hi) {
            int mid = lo + hi >> 1;
            if (d[1] * mid * (mid + 1) / 2 <= m)
                lo = mid;
            else
                hi = mid;
        }
        ll an = lo + 1;
        printf("%d\n", min(an, n));
        return 0;
    }
    l = 1, r = 1;
    for (int i = 2; i <= n; i++) {
        if (m >= d[i] * (r - l + 1)) {
            m -= d[i] * (r - l + 1);
            r++;
        } else {
            ll x = a[i - 1] - a[l];
            if (x >= d[i] * (r - l)) {
                m += x;
                m -= d[i] * (r - l);
                l++, r++;
            } else
                break;
        }
    }
    ans = r - l + 1;
    printf("%d\n", ans);
    return 0;
}

