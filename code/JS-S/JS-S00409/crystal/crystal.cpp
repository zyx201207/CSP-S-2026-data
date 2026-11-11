#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;
int n;
long long m, a[N + 10], c[N + 10];

bool check(int l, int r, long long x) {
    long long need = x * (r - l + 1) - (c[r] - c[l - 1]);
    return need <= m;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(mid, i, a[i])) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans = max(ans, i - r + 1);
    }
    printf("%d\n", ans);
    return 0;
}
