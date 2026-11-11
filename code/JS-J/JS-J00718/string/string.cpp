#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 8;
int n, a[N], c[N], suml, sumr;
long long p[N], ans;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d %c", &a[i], &c[i]);
    p[1] = 1ll;
    for (int i = 2; i <= n + 1; i++) p[i] = p[i - 1] + a[i - 1];
    for (int i = 1, j = n; i < j; ) {
        long long il = p[i], ir = p[i + 1] - 1ll;
        long long jl = p[n + 1] - (p[j + 1] - 1ll), jr = p[n + 1] - p[j];
        if (c[i] != c[j]) ans += min(jr, ir) - max(jl, il) + 1ll;
        if (ir < jr) i++;
        else if (ir > jr) j--;
        else i++, j--;
    }
    printf("%lld\n", ans);
    return 0;
}
