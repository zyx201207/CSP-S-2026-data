#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, LB = 500 + 10;
const long long INF = 1e18 + 10;
int c, n, m, d, q;
long long w[N];
int way[N][30];
long long ln[N][30];
long long lba[LB][LB];
int pre[N], idx = 0;
struct Node{
    int to, nxt;
    long long len;
}a[2 * LB * LB];
void add(int u, int v, long long len){
    a[++ idx].to = v;
    a[idx].nxt = pre[u];
    a[idx].len = len;
    pre[u] = idx;
}
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
bool vis[LB];
void bfs(int s){
    memset(vis, false, sizeof(vis));
    pq.push({0, s});
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        long long lenn = p.first;
        int h = p.second;
        if(!vis[h]){
            vis[h] = true;
            if(lba[s][h] == INF){
                lba[s][h] = lenn;
                lba[h][s] = lenn;
            }
        }else{
            continue;
        }
        for(int i = pre[h]; i; i = a[i].nxt){
            int to = a[i].to;
            long long le = a[i].len;
            if(!vis[to]){
                pq.push({le + lenn, to});
            }
        }
    }
}
int main(){
    freopen("subway.in", "r",stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i ++){
        scanf("%lld", &w[i]);
    }
    for(int i = 1; i <= n; i ++){
        int k, x;
        long long t;
        scanf("%d", &k);
        for(int j = 1; j <= k; j ++){
            scanf("%d%lld", &x, &t);
            way[x][++ way[x][0]] = i;
            ln[x][way[x][0]] = t;
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(i == j){
                lba[i][j] = 0;
            }else{
                lba[i][j] = INF;
            }
        }
    }
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= way[i][0]; j ++){
            for(int k = 1; k <= way[i][0]; k ++){
                int u = way[i][j], v = way[i][k];
                lba[u][v] = min(lba[u][v], ln[i][k] + ln[i][j]);
                lba[v][u] = lba[u][v];
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(lba[i][j] != INF && i != j){
                add(i, j, lba[i][j]);
                add(j, i, lba[j][i]);
                lba[i][j] = INF;
                lba[j][i] = INF;
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        bfs(i);
    }
    int x, y;
    while(q --){
        scanf("%d%d", &x, &y);
        long long ans = INF;
        for(int i = 1; i <= way[x][0]; i ++){
            for(int j = 1; j <= way[y][0]; j ++){
                int u = way[x][i], v = way[y][j];
                ans = min(ln[x][i] + ln[y][j] + lba[u][v], ans);
            }
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}
