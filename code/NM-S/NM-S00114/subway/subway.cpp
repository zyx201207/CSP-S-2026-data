#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, x, y;
const int N = 505, M = 5e5+5;
int w[M], k[N], a[N][M], t[N][M], dig[M][25], cnt[M], geng[N];
long long nxtt[N][N], good[N][N];
struct edge{
    long long v, tim;
};
struct node{
    long long v, from;
};
vector<edge> nxt[N];
void dij(int i){
    memset(geng, 0, sizeof geng);
    queue<node> q;
    q.push({i,-1});
    while(!q.empty()){
        node u = q.front();
        if(geng[u.v]==nxt[u.v].size()) return ;
        q.pop();
        for(edge e:nxt[u.v]){
            int v = e.v;
            if(v!=u.from){
                q.push({v,u.v});
            }
        }
        good[i][u.v] = min(good[i][u.v], good[i][u.from]+nxtt[u.from][u.v]);
        geng[u.v]++;
    }
    return ;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(good, 0x3f, sizeof(good));
    memset(nxtt, 0x3f, sizeof(nxtt));
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++) scanf("%d", &w[i]);
    for(int i = 1; i <= n; i++){
        scanf("%d", &k[i]);
        for(int j = 1; j <= k[i]; j++){
            scanf("%d%d", &a[i][j], &t[i][j]);
            dig[a[i][j]][++cnt[a[i][j]]] = i;
        }
    }
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= cnt[i]; j++)
            for(int k = 1; k <= cnt[i]; k++){
                int u = dig[i][j], v = dig[i][k];
                nxtt[u][v] = min(nxtt[u][v], (long long)(t[u][i]+t[v][i]));
            }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(nxtt[i][j]!=0x3f3f3f3f)
                nxt[i].push_back({j, nxtt[i][j]});
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            good[i][j] = nxtt[i][j];
    for(int i = 1; i <= n; i++) good[i][i] = 0, nxtt[i][i] = 0;
    for(int i = 1; i <= n; i++) dij(i);
    while(q--){
        cin >> x >> y;
        long long ans = w[x] + w[y], minn = 0x3f3f3f3f3f3f3f3f;
        for(int i = 1; i <= cnt[x]; i++){
            for(int j = 1; j <= cnt[y]; j++){
                int u = dig[x][i], v = dig[y][j];
                if(minn > good[u][v]+t[u][x]+t[v][y]) minn = good[u][v]+t[u][x]+t[v][y];
            }
        }
        cout << ans+minn << endl;
    }
    return 0;
}
