#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll offset = 1e12;

int n;
ll m, a[500010], s[500010];

bool check(int x) {
    for (int i = 1; i + x - 1 <= n; i++)
        if (1ll * x * a[i + x - 1] - (s[i + x - 1] - s[i - 1]) <= m)
            return true;
    return false;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), a[i] += offset;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int l = 0, r = n + 1;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", l);
    return 0;
}
