#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 200005;

bool vis[MAXN];
long long a[MAXN], ans;
int n, m;

void dfs(int pos, long long now) {
    if (pos > m) {
        ans = max(ans, now);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        if (pos == 1) {
            dfs(pos + 1, a[i]);
        } else dfs(pos + 1, now & a[i]);
        vis[i] = false;
    }
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long z;
    scanf("%d%d", &n, &m);
    z = a[1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (i == 1) continue;
        z = z & a[i];
    }
    if (m == n) {
        printf("%lld", z);
        return 0;
    }
    if (m == 1) {
        sort(a + 1, a + n + 1);
        printf("%lld", a[n]);
        return 0;
    }
    dfs(1, 0);
    printf("%lld", ans);
    return 0;
}
