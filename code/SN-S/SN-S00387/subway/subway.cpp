#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
#define pb push_back
#define bs basic_string
#define sz(v) (LL)(v).size()
#define cir(x) rep(__tmp, 1, x)
// #define rd(x) scanf("%lld", &(x))
#define all(v) (v).begin(), (v).end()
#define erg(i, pre, x) for(LL i = (pre)[x];i;i = a[i].next)
#define rep(i, l, r) for(LL i = (l), _tmp = (r);i <= _tmp;i++)
#define per(i, l, r) for(LL i = (l), _tmp = (r);i >= _tmp;i--)
typedef long long LL;
typedef pair<LL, LL> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f, INF_BIT = 0x3f;

const LL N = 510, M = 5e5 + 10, D = 20;

LL rd(LL &x){
    LL s = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){ if(ch == '-') f = -f; ch = getchar(); }
    while(isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
    return x = s * f;
}

LL id, n, m, d, q;
LL w[M];
LL s;
LL x, t;
LL u, v;

// struct Node{ LL from, to, len, next; };
// Node a[EDGES];
// LL ind;
// LL pre[NODES];
// void add(LL u, LL v, LL w){ ind++; a[ind] = {u, v, w, pre[u]}; pre[u] = ind; }
// void addu(LL u, LL v, LL w){ /* printf("-- %lld %lld %lld\n", u, v, w); */ add(u, v, w), add(v, u, w); }

vector<PII> sv[M];
LL g[N][N];

LL dis[N][N];
bool vis[N];
priority_queue<PII, vector<PII>, greater<PII>> qd;
void dijk(LL dis[], LL s){
    rep(i, 1, n) dis[i] = INF, vis[i] = false;
    dis[s] = 0;
    qd.push({dis[s], s});
    while(sz(qd)){
        auto it = qd.top();
        qd.pop();
        LL x = it.sec;
        if(vis[x]) continue;
        vis[x] = true;
        // erg(i, pre, x){
        //     LL to = a[i].to, len = a[i].len;
        rep(to, 1, n){
            if(x == to) continue;
            LL len = g[x][to];
            if(!vis[to] && dis[to] > dis[x] + len){
                dis[to] = dis[x] + len;
                qd.push({dis[to], to});
            }
        }
    }
}

LL ans;

void solve(){
    rd(id), rd(n), rd(m), rd(d), rd(q);
    rep(i, 1, m) rd(w[i]);
    rep(i, 1, n){
        rd(s);
        cir(s) rd(x), rd(t), sv[x].pb({i, t});
    }
    // cout << clock() <<endl; return;
    
    rep(i, 1, n) rep(j, 1, n) g[i][j] = INF;
    rep(i, 1, m){
        auto &v = sv[i];
        rep(p, 0, sz(v) - 1) rep(q, p + 1, sz(v) - 1) g[v[p].fir][v[q].fir] = min(g[v[p].fir][v[q].fir], v[p].sec + v[q].sec);
    }
    // cout << clock() <<endl; return;
    
    rep(i, 1, n) rep(j, i + 1, n) g[i][j] = g[j][i] = min(g[i][j], g[j][i]);
    rep(i, 1, n) dijk(dis[i], i);
    
    cir(q){
        ans = INF;
        rd(u), rd(v);
        if(u == v){ puts("0"); continue; }
        for(auto p : sv[u]) for(auto q : sv[v]) ans = min(ans, w[u] + w[v] + p.sec + q.sec + dis[p.fir][q.fir]);
        printf("%lld\n", ans);
    }
    // cout << clock() <<endl;
}

int main(){
    // freopen("1.in", "r", stdin);  //std=
    // freopen("1.out", "w", stdout);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    
    solve();
    return 0;
}
