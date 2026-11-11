#include <bits/stdc++.h>

using namespace std;
long long c, T, n;
unsigned long long d;
const long long INF = 1e18;
const long long N = 2e6 + 10;
long long f[N], g[N], ct[N], a[N];
vector<long long> ed[5005]; queue<long long> q;
long long dis[N], way[N], vis[N], ok[5005][5005];
int cl[N];
void work() {
    scanf("%lld%llu", &n, &d);
    for(long long i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(long long i = 1; i <= n; i++) {
        ct[i] = 0; cl[i] = 0;
        long long l = i, r = n;
        while(l < r) {
            long long mid = (l + r + 1) >> 1;
            __int128 len = a[mid] - a[i];
            if(len <= (__int128)d) l = mid;
            else r = mid - 1;
        }
        ct[i] = l;
        l = 1, r = i;
        while(l < r) {
            long long mid = (l + r) >> 1;
            __int128 len = a[i] - a[mid];
            if(len <= (__int128)d) r = mid;
            else l = mid + 1;
        }
        cl[i] = l;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) ok[i][j] = 0;
    for(long long i = 1; i <= n; i++) ed[i].clear();
    for(long long i = 1; i <= n; i++) {
        for(long long j = i + 1; j <= ct[i]; j++)
            ed[i].push_back(j);
        for(int j = cl[i]; j < i; j++)
            ed[i].push_back(j);
    }
    // for(long long i = 1; i <= n; i++) {
    //     for(long long j : ed[i]) printf("%d ", j);
    //     printf("\n");
    // }
    for(long long s = 1; s <= n; s++) {
        for(long long i = 1; i <= n; i++)
            dis[i] = INF, way[i] = 0, vis[i] = 0;
        q.push(s); dis[s] = 0, way[s] = 1;
        while(!q.empty()) {
            long long u = q.front(); q.pop();
            vis[u] = 1;
            for(long long v : ed[u]) {
                if(vis[v]) continue;
                if(dis[v] > dis[u] + 1)
                    dis[v] = dis[u] + 1, way[v] = 1, q.push(v);
                else if(dis[v] == dis[u] + 1) way[v] = way[v] + way[u];
            }
        }
        // for(long long i = 1; i <= n; i++) printf("%lld %lld\n", dis[i], way[i]);
        // printf("\n");
        for(long long i = 1; i <= n; i++)
            if(way[i] == 2) ok[s][i] = 1;
    }
    long long ans = 0;
    for(long long i = 1; i <= n; i++)
        for(long long j = i + 1; j <= n; j++)
            if(ok[i][j] || ok[j][i]) ans++;
    printf("%lld\n", ans);
    return;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld%lld", &c, &T);
    while(T--) work();
}