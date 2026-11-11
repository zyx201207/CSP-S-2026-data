#include<bits/stdc++.h>
#define ll long long
#define mxn 500003
#define md 998244353
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rept(i,a,b) for(int i=(a);i<(b);++i)
#define drep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
    int x=0;bool fl=0;char c=getchar();
    while(!isdigit(c)){if(c=='-')fl=1;c=getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return fl?-x:x;
}
int n,m,d,q,a[mxn];
ll f[503][503];
vector<pair<int,int>>g[mxn];
const ll INF=1e18;
inline void chk(ll &x,ll y){
    if(y<x)x=y;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(),n=read(),m=read(),d=read(),q=read();
    rep(i,1,m)a[i]=read();
    for(int i=1,k,x,d;i<=n;++i){
        k=read();
        while(k--){
            x=read(),d=read();
            g[x].pb({i,d});
        }
    }
    memset(f,0x3f,sizeof(f));
    rep(i,1,n)f[i][i]=0;
    rep(i,1,m){
        for(auto &x:g[i])for(auto &y:g[i]){
            chk(f[x.first][y.first],x.second+y.second);
        }
    }
    rep(k,1,n)rep(i,1,n)rep(j,1,n)chk(f[i][j],f[i][k]+f[k][j]);
    int x,y;
    while(q--){
        x=read(),y=read();
        ll ans=INF;
        for(auto &i:g[x])for(auto &j:g[y])ans=min(ans,f[i.first][j.first]+i.second+j.second);
        cout<<ans+a[x]+a[y]<<'\n';
    }
    return 0;
}