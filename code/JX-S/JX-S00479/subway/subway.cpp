#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define INF 0x3f3f3f3f
#define endl '\n'
// #define int ll
using namespace std;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0' or ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while (ch>='0' and ch<='9') x=x*10+(ll)(ch-'0'),ch=getchar();
    return x*f;
}
ll gcd(ll x,ll y){
    if (y==0) return x;
    return gcd(y,x%y);
}
ll qpow(ll x,ll y,ll mod){
    ll ans=1;
    if (mod==-1) mod=1e18;
    while (y){
        if (y&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return ans;
}
const int N=5e5,M=500,W=1e3;
int m,n,wei,c[N+5],len[M+5];
ll dis[N+5],di[W+5][W+5];;
vector<pair<int,ll> > a[N+5];
vector<pair<int,ll> > e[M+5];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
void bfs(int st){
    for (int i=1;i<=n;i++) dis[i]=1e9;
    dis[st]=0;
    q.push({0,st});
    while (!q.empty()){
        int u=q.top().second,val=q.top().first;
        q.pop();
        if (dis[u]!=val) continue;
        for (pair<int,ll> x:a[u]){
            for (pair<int,ll> y:e[x.first]){
                int v=y.first;
                if (v==u) continue;
                ll tim=val+x.second+y.second;
                if (dis[v]>tim){
                    // cerr<<u<<" "<<v<<" "<<x.first<<" "<<x.second<<" "<<y.second<<" "<<tim<<endl;
                    dis[v]=tim;
                    q.push({tim,v});
                }
            }
        }
    }
}
void solve(){
    int tt;
    m=read(),n=read(),wei=read(),tt=read();
    for (int i=1;i<=n;i++) c[i]=read();
    for (int i=1;i<=m;i++){
        len[i]=read();
        for (int j=1;j<=len[i];j++){
            int v=read(),t=read();
            e[i].push_back({v,t});
            a[v].push_back({i,t});
        }
    }
    for (int i=1;i<=n;i++){
        bfs(i);
        for (int j=1;j<=n;j++) di[i][j]=dis[j];
    }
    while (tt--){
        int l=read(),r=read();
        printf("%lld\n",di[l][r]+c[l]+c[r]);
    }
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll cc=read();
    ll t=1;
    while (t--) solve();
    return 0;
}