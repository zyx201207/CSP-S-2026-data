#include<bits/stdc++.h>
#define FILE "migrate"
using namespace std;
using i64 = long long;

namespace FakeWilson {
const int N = 1e6 + 5;
const int M = 5e3 + 5;
int head[N], num[N];
i64 a[N], dis[N];
int cnt;

struct Edge {
    int to, next;
} e[N << 2];

void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void solve() {
    int n; i64 d;
    scanf("%d%lld", &n, &d), cnt = 0;
    for(int i = 1; i <= n; i++) head[i] = 0;
    for(int i = 1; i <= n; i++) scanf("%lld", a + i);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) dis[j] = 2e18 + 1;
        dis[i] = 0, num[i] = 1;
        for(int j = i; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                if(a[k] - a[j] > d) break;
                if(dis[k] > dis[j] + 1) {
                    dis[k] = dis[j] + 1;
                    num[k] = num[j];
                } else if(dis[k] == dis[j] + 1) {
                    num[k] += num[j];
                    num[k] = min(num[k], 10);
                }
            }
        }
        for(int j = i; j <= n; j++) if(num[j] == 2) ans++;
    }
    printf("%d\n", ans);
}

signed main() {
    int c, T;
    scanf("%d%d", &c, &T);
    while(T--) solve();
    return 0;
}

}

signed main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    return FakeWilson::main();
}
