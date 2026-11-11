#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 500010;

int n, ans;
LL m, a[N], ps[N];

bool Check(int l, int r) {
    return 1LL * (r - l + 1) * a[r] - (ps[r] - ps[l - 1]) <= m;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + a[i];
    for (int i = 1; i <= n; ++i) {
        int l = i, r = n + 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (Check(i, mid)) l = mid;
            else r = mid - 1;
        }
        if (r <= n) ans = max(ans, l - i + 1);
    }

    printf("%d\n", ans);

    return 0;
}
// rp++
// jbw tql ORZ
