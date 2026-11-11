#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define all(v) v.begin(),v.end()
#define lowbit(x) (x&-x)
#define pll pair<ll,ll>
#define x first
#define y second
const int N = 503, M = 40003, mod = 998244353;
int k[M],dis[N][M+N];
int c,n,m,d,q;
bool done[M+N];
vector<pii> g[M+N];
inline int plt(int k) { return m+k; }
inline int dtk(int k) { return k; }
inline int zt(int k) { return n+m+k; }
void adeg(int u,int v,int w) {
    g[u].pb({v,w});
    g[v].pb({u,w});
}
void dijkstra(int s) {
    priority_queue<pii> pq;
    memset(dis[s],0x3f,sizeof dis[s]);
    memset(done,0,sizeof done);
    dis[s][s]=0;
    pq.push({-dis[s][s],s});
    while(pq.size()) {
        pii tp=pq.top(); pq.pop();
        int u=tp.y;
        if(done[u]) return;
        done[u]=1;
        for(auto e:g[u]) {
            int v=e.x,w=e.y;
            if(dis[s][v]>dis[s][u]+w) {
                dis[s][v]=dis[s][u]+w;
                pq.push({-dis[s][v],v});
            }
        }
    }
    
}
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m) {
        int w; cin>>w;
        adeg(dtk(i),zt(i),w);
    }
    rep(i,1,n) {
        cin>>k[i];
        rep(j,1,k[i]) {
            int a,t; cin>>a>>t;
            adeg(zt(a),plt(i),t);
        }
    }
    rep(i,1,m) dijkstra(dtk(i));
    while(q--) {
        int u,v; cin>>u>>v;
        cout<<dis[dtk(u)][dtk(v)]<<'\n';
    }
    return 0;
}
/*
remember freopen
long long
initialize
*/