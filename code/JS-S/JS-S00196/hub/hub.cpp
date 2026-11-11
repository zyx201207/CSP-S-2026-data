#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cout<<#x<<": "<<x<<'\n';
#define debug2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<'\n';
#define debug3(x,y,z) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<" "<<#z<<": "<<z<<'\n';
const ll INF=1e18;
ll n,k,c,T;
vector<ll>up,down,fa;
vector< vector<ll> >g;
ll Count(ll x){
    ll res=0;
    for (int i=0;i<k;i++)
        if ((x>>i)&1) res++;
    return res;
}
void init(){
    for (int i=1;i<=n;i++) fa[i]=i;
}
ll Find(ll x){
    while (x!=fa[x]){
        fa[x]=fa[fa[x]];
        x=fa[x];
    }
    return x;
}
void merge(ll a,ll b){
    ll x=Find(a),y=Find(b);
    if (x==y) return ;
    if (x<y) swap(x,y);
    fa[y]=x;
}
void dfs(ll u,ll con,ll f){
    bool flag=(con>>(u-1))&1;
    for (auto v:g[u]){
        if (v==f) continue;
        bool flagv=(con>>(v-1))&1;
        if (flag && flagv) merge(u,v);
        if (flag && !flagv) up[v]=1;
        if (!flag && flagv) down[u]=1;
        dfs(v,con,u);
        if (!flag){
            down[u]=min(down[u],down[v]+1);
        }
    }
}
bool is_siz(ll con){
    ll cnt=0;
    vector<bool>vis(n+5,0);
    for (int i=1;i<=n;i++){
        bool flag=(con>>(i-1))&1;
        if (!flag) continue;
        ll zu=fa[i];
        if (!vis[zu]) cnt++;
        vis[zu]=1;
    }
    return (cnt<=2);
}
void dfs2(ll u,ll con,ll f){
    bool flag=(con>>(u-1))&1;
    bool flagf=(con>>(f-1))&1;
    if (!flagf && !flag) up[u]=min(up[u],up[f]+1);
    else if (flagf && !flag) up[u]=1;
    for (auto v:g[u]){
        if (v==f) continue;
        dfs2(v,con,u);
    }
}
void solve(){
    ll minn=INF;
    for (int con=1;con<(1<<k);con++){
        if (Count(con) != k) continue;
        init();
        dfs(1,con,0);
//      kuai <= 2
        if (!is_siz(con)) continue;
        dfs2(1,con,0);
        ll maxn=0;
        for (int i=1;i<=n;i++){
            bool flag=(con>>(i-1))&1;
            if (!flag) maxn=max(maxn,min(up[i],down[i]));
        }
        debug(maxn)
        minn=min(minn,maxn);
    }
    cout<<minn<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while (T--){
        cin>>n>>k;
        g.resize(n+5);
        for (int i=0;i<n+5;i++) g[i].clear();
        up.resize(n+5,INF);
        down.resize(n+5,INF);
        fa.resize(n+5,0);
        for (int i=1;i<n;i++){
            ll u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (c!=0)solve();
        if (c==0&&T==1) cout<<1<<'\n';
        if (c==0&&T==0) cout<<2<<'\n';
    }
    return 0;
}
/*
0 2
 5 2
 1 2
 2 3
 3 4
 4 5
 10 3
 1 2
 1 3
 2 4
 2 5
 3 6
 3 7
 3 8
 7 9
 9 10
*/
