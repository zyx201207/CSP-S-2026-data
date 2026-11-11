#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int n, m, a[N], f[N];
bool used[N];
long long ans;
void dfs(int x) {
    if (x == m + 1) {
        long long c = f[1];
        for (int i = 2;i <= m;i++)
            c &= f[i];
        ans = max(ans, c);
        return;
    }
    for (int i = 1;i <= n;i++)
        if (!used[i]) {
            used[i] = true;
            f[x] = a[i];
            dfs(x + 1);
            used[i] = false;
        }
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++)
        scanf("%d", &a[i]);
    dfs(1);
    printf("%lld", ans);
}
