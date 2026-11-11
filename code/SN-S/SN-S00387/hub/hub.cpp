#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
#define pb push_back
#define bs basic_string
#define sz(v) (LL)(v).size()
#define cir(x) rep(__tmp, 1, x)
#define rd(x) scanf("%lld", &(x))
#define all(v) (v).begin(), (v).end()
#define erg(i, pre, x) for(LL i = (pre)[x];i;i = a[i].next)
#define rep(i, l, r) for(LL i = (l), _tmp = (r);i <= _tmp;i++)
#define per(i, l, r) for(LL i = (l), _tmp = (r);i >= _tmp;i--)
typedef long long LL;
typedef pair<LL, LL> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f, INF_BIT = 0x3f;

const LL N = 1e6 + 10;

LL id, t;
LL n, m;
LL u, v;

struct Node{ LL from, to, next; };
Node a[N * 2];
LL ind;
LL pre[N];
void add(LL u, LL v){ ind++; a[ind] = {u, v, pre[u]}; pre[u] = ind; }

LL fa[N];
LL find(LL x){ return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(LL x, LL y){ fa[find(x)] = find(y); }

LL dis[N];
bool vis[N];
queue<LL> q;
void bfs(LL st){
    rep(i, 1, n) dis[i] = INF, vis[i] = false;
    rep(i, 0, n - 1) if((st >> i) & 1) dis[i + 1] = 0, vis[i + 1] = true, q.push(i + 1);
    while(sz(q)){
        auto it = q.front();
        q.pop();
        LL x = it;
        erg(i, pre, x){
            LL to = a[i].to;
            if(!vis[to] && dis[to] > dis[x] + 1){
                dis[to] = dis[x] + 1;
                vis[to] = true;
                q.push(to);
            }
        }
    }
}

LL ans = INF;

void solve(){
    rd(id), rd(t);
    cir(t){
        ind = 0;
        rep(i, 1, n) pre[i] = 0;
        
        ans = INF;
        
        rd(n), rd(m);
        cir(n - 1) rd(u), rd(v), add(u, v), add(v, u);
        
        rep(st, 0, (1 << n) - 1) if(__builtin_popcount(st) == m){
            // rep(i, 1, n) if((st >> (i - 1)) & 1) printf("%lld ", i);
            // puts("");
            iota(fa + 1, fa + n + 1, 1ll);
            rep(x, 1, n) if((st >> (x - 1)) & 1){
                erg(i, pre, x){
                    LL to = a[i].to;
                    if((st >> (to - 1)) & 1) merge(x, to);
                }
            }
            LL x = 0, y = 0;
            rep(i, 1, n) if((st >> (i - 1)) & 1){
                LL t = find(i);
                // cout << i << ',' << t << '|' << x << ',' << y << ' ';
                if(x == t || y == t) continue;
                if(x == 0) x = t;
                else if(y == 0) y = t;
                else{ x = y = -1; break; }
            }
            // cout << x << ' ' << y <<endl;
            // cout <<endl;
            if(x == -1) continue;
            // rep(i, 1, n) if((st >> (i - 1)) & 1) printf("%lld ", i);
            // puts("");
            bfs(st);
            LL ma = 0;
            rep(i, 1, n) ma = max(ma, dis[i]);
            ans = min(ans, ma);
        }
        
        printf("%lld\n", ans);
        // break;
    }
}

int main(){
    // freopen("hub3.in", "r", stdin);  //std=
    // freopen("1.out", "w", stdout);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    
    solve();
    return 0;
}
