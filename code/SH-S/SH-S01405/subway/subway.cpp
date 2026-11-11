#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 5e2 + 5, M = 5e5 + 5, D = 25;
const ll INF = 1e18;
int n, m, d, q, w[M], cnt[M];
ll dis[N][N];
void chkmin(ll &a, ll b){
    if (a > b){
        a = b;
    }
}
struct node{
    int id, t;
    node(int _id = 0, int _t = 0): id(_id), t(_t) {}
}p[M][D];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%*d%d%d%d%d", &n, &m, &d, &q);
    for (int i = 1; i <= m; i++){
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++){
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++){
            int u, t;
            scanf("%d%d", &u, &t);
            p[u][++cnt[u]] = node(i, t);
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j){
                continue;
            }
            dis[i][j] = INF;
        }
    }
    for (int u = 1; u <= m; u++){
        for (int i = 1; i <= cnt[u]; i++){
            for (int j = 1; j <= cnt[u]; j++){
                if (i == j){
                    continue;
                }
                chkmin(dis[p[u][i].id][p[u][j].id], p[u][i].t + p[u][j].t);
            }
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                chkmin(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--){
        int x, y;
        ll ans = INF;
        scanf("%d%d", &x, &y);
        for (int i = 1; i <= cnt[x]; i++){
            for (int j = 1; j <= cnt[y]; j++){
                chkmin(ans, dis[p[x][i].id][p[y][j].id] + p[x][i].t + p[y][j].t + w[x] + w[y]);
            }
        }
        printf("%lld\n", ans);
    }
}