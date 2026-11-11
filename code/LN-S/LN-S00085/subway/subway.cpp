#include <bits/stdc++.h>

using namespace std;

using ci = const int;
using cll = const long long;
using ll = long long;
using ull = unsigned long long;
using pii = pair <int,int>;

namespace namespace_qwq {

ci N = 1e3 + 5;
ci idN = 5e5 + 5;
ci inf = 0x7f7f7f7f;
cll LLinf = 1e18;
cll mod = 998244353;

template <typename T>
inline void cmax(T &x,const T &y) {if(y > x) x = y;}

template <typename T>
inline void cmin(T &x,const T &y) {if(y < x) x = y;}

int c,n,m,d,qqqqqq;
ll w[N];
int k[N];
int a[N][N];
int rk[N][N];
ll t[N][N];

vector <int> id[N];

inline int getid(ci &pid,ci &sid) {return n * (pid - 1) + sid;}

struct edge {
    int to;
    ll w;
    edge() {}
    edge(int _to,ll _w) {to = _to,w = _w;}
};
vector <edge> gr[idN];

ll dis[idN],vis[idN];

struct node {
    int id;
    ll w;
    node() {}
    node(int _u,ll _w) {id = _u,w = _w;}
    inline bool operator < (const node &x) const {
        return w > x.w;
    }
};
priority_queue <node> q;

inline void dijkstra(int s,int sid) {
    for(int i = 1;i <= m;i++) {
        for(ci &id : id[i]) dis[getid(i,id)] = LLinf,vis[getid(i,id)] = 0;
    }
    dis[getid(s,sid)] = 0;
    q.emplace(getid(s,sid),0);
    node u;
    while(!q.empty()) {
        u = q.top();
        q.pop();
        if(vis[u.id]) continue;
        vis[u.id] = 1;
        for(const auto &v : gr[u.id]) {
            if(dis[u.id] + v.w < dis[v.to]) {
                dis[v.to] = dis[u.id] + v.w;
                q.emplace(v.to,dis[v.to]);
            }
        }
    }
}

ll wdis[N][N];

inline void Main() {
    cin >> c >> n >> m >> d >> qqqqqq;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++) {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++) {
            cin >> a[i][j];
            cin >> t[i][a[i][j]];
            id[a[i][j]].emplace_back(i);
            rk[i][a[i][j]] = j;
        }
    }
    for(int u = 1,v,p,q;u <= m;u++) {
        for(v = 1;v <= m;v++) {
            for(ci &idu : id[u]) {
                for(ci &idv : id[v]) {
                    p = getid(u,idu),q = getid(v,idv);
                    if(p == q) continue;
                    if(idu != idv) gr[p].emplace_back(q,t[idu][u] + t[idv][v]);
                    else if(rk[idu][u] < rk[idu][v]) gr[p].emplace_back(q,0);
                }
            }
        }
    }
    memset(wdis,0x7f,sizeof wdis);
    for(int u = 1,v;u <= m;u++) {
        for(ci &idu : id[u]) {
            dijkstra(u,idu);
            for(v = 1;v <= m;v++) {
                for(ci &idv : id[v]) {
                    if(u == v) continue;
                    cmin(wdis[u][v],w[idu] + t[idu][u] + w[idv] + t[idv][v] + dis[getid(v,idv)]);
                }
            }
        }
    }
    for(int i = 1,x,y;i <= qqqqqq;i++) {
        cin >> x >> y;
        cout << wdis[x][y] << "\n";
    }
}

};

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    namespace_qwq::Main();
    return 0;
}