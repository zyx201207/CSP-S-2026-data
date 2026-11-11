#include<bits/stdc++.h>
using namespace std;
// #define int long long
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
const int N = 205, mod = 998244353;
vector<int> g[N];
vector<pii> eg;
int du,dv;
int dis[N];
int n,k,mx,mxid;
int f[N],farst[N];
int trsz;
void findfar(int u,int fa) {
    dis[u]=dis[fa]+1,f[u]=fa;
    if(dis[u]>mx) mx=dis[u],mxid=u;
    for(auto v:g[u]) {
        if(u==du&&v==dv) continue;
        if(v==du&&u==dv) continue;
        if(v==fa) continue;
        findfar(v,u);
    }
}
int findfa(int u,int w) {
    rep(i,1,w) u=f[u];
    return u;
}
void dfs(int u,int fa) {
    farst[u]=0; trsz++;
    for(auto v:g[u]) {
        if(u==du&&v==dv) continue;
        if(v==du&&u==dv) continue;
        if(v==fa) continue;
        dfs(v,u);
        farst[u]=max(farst[u],farst[v]+1);
    }
}
int dp[N][N][N]; // dp[i,j] at vertix i use j color mindis 
int ret[N][N];
void rdfs(int u,int fa,int num) {
    int now=0;
    // rep(i,0,num) dp[u][i][0]=dp[u][i][1]=1e9;
    rep(i,1,num) dp[u][i][0]=0;
    dp[u][0][0]=ret[u][0]=farst[u];
    for(auto v:g[u]) {
        if(u==du&&v==dv) continue;
        if(v==du&&u==dv) continue;
        if(v==fa) continue;
        rdfs(v,u,num);
        now++;
        rep(i,1,num) dp[u][i][now]=max(dp[u][i][now-1],farst[v]+1);
        rep(i,1,num) rep(j,1,num-1) dp[u][i][now]=min(dp[u][i][now],max(dp[u][i-j][now-1],ret[v][j]));
    }
    rep(i,1,num) ret[u][i]=dp[u][i][now];
    // cerr<<"vertix #"<<u<<": ";
    rep(i,1,num) {
        if(num<=now) ret[u][i]=dp[u][i][now];
        else ret[u][i]=ret[u][i-1];
    }
    // rep(i,0,num) cerr<<ret[u][i]<<" \n"[i==num];
}
int trial(int rt,int num) {
    // cerr<<"trial: "<<rt<<" "<<num<<'\n';
    trsz=0,dfs(rt,0);
    rdfs(rt,0,min(trsz,num));
    return ret[rt][min(trsz,num)];
}
int cal(int rt,int num) {
    rep(i,1,n) dis[i]=0;
    mx=0,mxid=rt,dis[0]=-1;
    findfar(rt,0);
    int newrt=mxid;
    rep(i,1,n) dis[i]=0;
    mx=0,mxid=newrt,dis[0]=-1;
    findfar(newrt,0);
    int rt1=findfa(mxid,mx/2);
    int rt2=findfa(mxid,(mx+1)/2);
    // cerr<<"diameter: "<<mx<<", rts: "<<rt1<<' '<<rt2<<'\n';
    if(num==1) {
        int resa=trial(rt1,num),resb=trial(rt2,num);
        return min(resa,resb);
    } return trial(rt1,num);
}
void solve() {
    cin>>n>>k;
    rep(i,1,n) g[i].clear();
    rep(i,1,n-1) {
        int u,v; cin>>u>>v;
        g[u].pb(v),g[v].pb(u);
        eg.pb({u,v});
    } int res=1e9;
    for(auto e:eg) {
        du=e.x,dv=e.y;
        // cerr<<"disconnect: "<<du<<", "<<dv<<"\n";
        rep(i,1,k-1) {
            int a=cal(du,i),b=cal(dv,k-i);
            res=min(res,max(a,b));
            // cerr<<"ltk1: "<<i<<' '<<a<<", ltk2: "<<k-i<<' '<<b<<'\n';
        }
    } cout<<res<<'\n';
}
signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t; cin>>c>>t;
    while(t--) solve();
    return 0;
}
/*
remember freopen
long long
initialize
*/