#include<bits/stdc++.h>
#define rep(i, j, k) for(int i=(j); i<=(k); i++)
#define per(i, j, k) for(int i=(j); i>=(k); i--)
#define debug(a...) _debug(#a, a)
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
template<class T> void _debug(const char *s, T x){cout<<s<<'='<<x<<endl;}
template<class T, class... Nxt> void _debug(const char *s, T x, Nxt... nxt){
    int d=0;
    while(d||*s!=',') d+=*s=='(', d-=*s==')', cout<<*s++;
    cout<<'='<<x<<',';
    _debug(s+1, nxt...);
}
const int N=1e6+5;
int n, k, ans;
vector<int> G[N];
vector<pair<int, int>> e;

int fa[N], dep[N], mxd[N], buc[N], rt, ban;

void dfs1(int u, int p){
    fa[u]=p;
    if(dep[u]>dep[rt]) rt=u;
    for(auto v:G[u]) if(v!=p && v!=ban){
        dep[v]=dep[u]+1;
        dfs1(v, u);
    }
}

void dfs2(int u, int p){
    mxd[u]=0;
    for(auto v:G[u]) if(v!=p && v!=ban){
        dfs2(v, u);
        mxd[u]=max(mxd[u], mxd[v]+1);
    }
    if(p) buc[mxd[u]]++;
    else buc[n]++;
}

void solve(int u, int p){
    ban=p, rt=0;
    dep[u]=0, dfs1(u, 0);
    int x=rt;
    dep[x]=0, dfs1(x, 0);
    int y=rt;
    rep(_, 1, dep[y]/2) rt=fa[rt];
    dfs2(rt, 0);
}

void run(){
    rep(i, 1, n) G[i].clear();
    cin>>n>>k;
    e.resize(n-1);
    for(auto &[u, v]:e){
        cin>>u>>v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    ans=n;
    dep[0]=-1;
    for(auto [u, v]:e){
        rep(i, 0, n) buc[i]=0;
        solve(u, v);
        solve(v, u);
        per(i, n-1, 0) buc[i]+=buc[i+1];
        rep(i, 0, n) if(buc[i]<=k){
            ans=min(ans, i);
            break;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    // file("hub");
    cin.tie(0)->sync_with_stdio(0);
    int c, t;
    cin>>c>>t;
    while(t--) run();
}