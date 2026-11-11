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
using ll=long long;
const int N=5000+5;
int n, f[N], g[N];
ll d, a[N];
vector<int> G[N];

void run(){
    rep(i, 1, n) G[i].clear();
    cin>>n>>d;
    rep(i, 1, n) cin>>a[i];
    rep(i, 1, n) rep(j, i+1, n) if(a[j]-a[i]<=d) G[i].emplace_back(j);
    ll ans=0;
    rep(i, 1, n){
        rep(j, 1, n) f[j]=-1, g[j]=0;
        queue<int> q;
        q.emplace(i);
        f[i]=0, g[i]=1;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto v:G[u])
                if(f[v]==-1){
                    f[v]=f[u]+1, g[v]=g[u];
                    q.emplace(v);
                } else if(f[v]==f[u]+1){
                    g[v]+=g[u];
                    g[v]=min(g[v], 3);
                }
        }
        rep(j, i+1, n) if(g[j]==2) ans++;//, debug(i, j);
    }
    cout<<ans<<'\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int c, t;
    cin>>c>>t;
    rep(tc, 1, t){
        run();
    }
}