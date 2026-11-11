#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int a, t;
}que[500001];
const int inf = 0x3f3f3f3f3f3f3f3f;
vector<node> sub[501], nsub[500001];
int tag, n, m, d, q, dis[501][501], w[500001];
void build(int x){
    for (int i = 0; i < nsub[x].size(); i++){
        int u = nsub[x][i].a, t1 = nsub[x][i].t;
        for (int j = i + 1; j < nsub[x].size(); j++){
            int v = nsub[x][j].a, t2 = nsub[x][j].t;
            dis[u][v] = dis[v][u] = min(dis[u][v], t1 + t2);
        }
    }
}
void solve(int x, int y){
    int ans = inf;
    for (int i = 0; i < nsub[x].size(); i++)
        for (int j = 0; j < nsub[y].size(); j++)
            ans = min(ans, dis[nsub[x][i].a][nsub[y][j].a] + nsub[x][i].t + nsub[y][j].t);
    ans += (w[x] + w[y]);
    cout << ans << '\n';
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> tag >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++){
            int a, t;
            cin >> a >> t;
            sub[i].push_back({a, t});
            nsub[a].push_back({i, t});
        }
    }
    for (int i = 1; i <= q; i++)
        cin >> que[i].a >> que[i].t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                dis[i][j] = inf;
    for (int i = 1; i <= m; i++)
        build(i);
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dis[i][k] != inf && dis[j][k] != inf && dis[i][j] > dis[i][k] + dis[j][k])
                    dis[i][j] = dis[i][k] + dis[j][k];
    for (int i = 1; i <= q; i++)
        solve(que[i].a, que[i].t);
    return 0;
}
