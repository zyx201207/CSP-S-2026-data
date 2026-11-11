#include <cstdio>
#include <queue>
#include <cstring>
typedef long long ll;
const int N = 2e6;
int fm[N], to[N], w[N], lst[N], nxt[N], ed = 1;
inline void add(int u, int v, int t){
    fm[ed] = u, to[ed] = v, w[ed] = t;
    nxt[ed] = lst[u], lst[u] = ed ++;
}
struct ob{
    int pos;
    ll sum;
};
inline bool operator < (ob a, ob b){
    return a.sum < b.sum;
}
int z, n, m, d, Q;
ll W[N];
ll dis[N];
ll minPath(int u, int v){
    for(int i = 1; i <= m; i++) dis[i] = 0x3f3f3f3f3f3f3f3f;
    std::priority_queue <ob> q;
    q.push({u, 0});
    dis[u] = 0;
    while(q.size()){
        const int p = q.top().pos;
        const ll s = q.top().sum;
        q.pop();
        if(s > dis[p]) continue;
        for(int i = lst[p]; i; i = nxt[i]){
            const int ns = s + w[i];
            if(dis[to[i]] > ns){
                dis[to[i]] = ns;
                q.push({to[i], ns});
            }
        }
    }
    return dis[v];
}
void init(){
    for(int i = 1; i <= m; i++) scanf("%lld", &W[i]);
    for(int i = 1; i <= n; i++){
        int pv = 0, nw, t, k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            scanf("%d %d", &nw, &t);
            if(j){
                add(pv, nw, t);
                add(nw, pv, t);
            }
            pv = nw;
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d %d %d %d %d", &z, &n, &m, &d, &Q);
    init();
    while(Q--){
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%lld\n", minPath(u, v) + W[u] + W[v]);
    }
    return 0;
}