#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <deque>
#include <set>
#include <bitset>
#define ll long long

using namespace std;

const int maxn = 507, maxm = 5e5+7;
const ll INF = 1e18;
int c, n, m, d, q;
int w[maxm];
struct edge{
    int u, w;
};
vector <edge> st[maxm];
ll dis[maxn][maxn];

ll minl(ll x, ll y){
    if(x < y) return x;
    return y;
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++)
        scanf("%d", &w[i]);
    for(int i = 1, cnt; i <= n; i++){
        scanf("%d", &cnt);
        for(int j = 1, u, t; j <= cnt; j++){
            scanf("%d%d", &u, &t);
            st[u].push_back({i, t});
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dis[i][j] = INF;
    for(int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < st[i].size(); j++)
            for(int k = 0; k < st[i].size(); k++){
                int u = st[i][j].u, v = st[i][k].u;
                dis[u][v] = minl(dis[u][v], st[i][j].w + st[i][k].w);
            }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = minl(dis[i][j], dis[i][k] + dis[k][j]);
    for(int i = 1, s, t; i <= q; i++){
        scanf("%d%d", &s, &t);
        ll ans = INF;
        for(int j = 0; j < st[s].size(); j++)
            for(int k = 0; k < st[t].size(); k++){
                int u = st[s][j].u, v = st[t][k].u;
                ans = minl(ans, dis[u][v]+st[s][j].w+st[t][k].w);
            }
        ans += w[s] + w[t];
        printf("%lld\n", ans);
    }
    return 0;
}
