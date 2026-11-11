#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, s[200005], maxn;
bool v[200005];
void dfs(int l, int k) {
    k++;
    if (k > m) {
        maxn = max(maxn, l);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) {
            v[i] = 1;
            if (l = -INT_MAX) l = s[i];
            else {
                l ^= s[i];
            }
            dfs(l, k);
        }
    }
}
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &s[i]);
    }
    dfs(-INT_MAX, 0);
    printf("%lld", maxn);
    return 0;
}
