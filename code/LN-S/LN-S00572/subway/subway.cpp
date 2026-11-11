# include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 505;

struct node{
    int u, w;
    bool operator < (const node & a) const{
        return w > a.w;
    }
};
priority_queue <node> q;
int C, m, n, D, qqq, w[N], kl[N];
vector <pair <int, int> > k[M], g[N];

bool vs[N], vs2[N];
long long dis[N];
long long solve(int x, int y){
    while (! q.empty()) q.pop();
    for (int i = 1; i <= n; i ++) vs[i] = vs2[i] = 0;
    memset(dis, 0x3f, sizeof(dis));
    q.push((node){x, 0});
    dis[x] = 0;
    while (! q.empty()){
        int u = q.top().u; q.pop();
        if (vs[u]) continue;
        vs[u] = 1;
        for (auto nx : g[u]){
            int kkk = nx.first, ttt = nx.second;
            for (auto v : k[kkk]) if (dis[v.first] > dis[u] + ttt + v.second){
                dis[v.first] = dis[u] + ttt + v.second;
                q.push((node){v.first, dis[v.first]});
            }
        }
    }
    return dis[y];
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", & C, & m, & n, & D, & qqq);
    for (int i = 1; i <= n; i ++) scanf("%d", & w[i]);
    for (int i = 1; i <= m; i ++){
        scanf("%d", & kl[i]);
        for (int j = 1, u, t; j <= kl[i]; j ++){
            scanf("%d%d", & u, & t);
            g[u].push_back({i, t});
            k[i].push_back({u, t});
        }
    }
    for (int i = 1, x, y; i <= qqq; i ++){
        scanf("%d%d", & x, & y);
        long long ans = w[x] + w[y];
        printf("%lld\n", ans + solve(x, y));
    }
    return 0;
}
