#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <typename T>
using vec = vector<T>;

const int C = 5e5 + 5;

int n;
ll m, a[C], d[C], sum[C];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a + 1, a + 1 + n);

    for (int i = 2; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i] - a[i - 1];
    }

    int ans = 1;
    ll k = 0;
    for (int l = 1, r = 1; r <= n; r++) {
        k = k + (r - l) * (a[r] - a[r - 1]);
        while (k > m) {
            k -= (sum[r] - sum[l]);
            l++;
        }
        ans = max(ans, r - l + 1);
    }

    printf("%d\n", ans);

    return 0;
}