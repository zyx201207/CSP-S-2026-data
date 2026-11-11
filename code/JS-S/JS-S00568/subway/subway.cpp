#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back

const int N=500+9,M=5e5+9;
inline int lowbit(int x){return x&(-x);}
inline void chkmin(int &x,int y){x=x<y?x:y;}
inline void chkmax(int &x,int y){x=x>y?x:y;}
inline void chkmin(ll &x,ll y){x=x<y?x:y;}
inline void chkmax(ll &x,ll y){x=x>y?x:y;}

#define INF (long long)(1e16)
int n,m,d,q; ll w[M],dis[N][N];
vector<pair<int,ll> > s[M];
void Mian(int TestCase){
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i){
        int k; cin>>k;
        while(k--){
            int x; ll t; cin>>x>>t;
            s[x].pb({i,t});
        }
    }
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) dis[i][j]=INF;
    for(int i=1;i<=m;++i){
        for(int x=0;x<s[i].size();++x){
            for(int y=x+1;y<s[i].size();++y){
                int u=s[i][x].fir,v=s[i][y].fir;
                ll t=s[i][x].sec+s[i][y].sec;
                chkmin(dis[u][v],t); chkmin(dis[v][u],t);
            }
        }
    }
    for(int i=1;i<=n;++i) dis[i][i]=0;
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i) if(dis[i][k]!=INF){
            for(int j=1;j<=n;++j) if(dis[k][j]!=INF){
                chkmin(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v; cin>>u>>v;
        ll ans=INF;
        for(auto xf:s[u]) for(auto yf:s[v]){
            int x=xf.fir,y=yf.fir;
            chkmin(ans,xf.sec+yf.sec+dis[x][y]);
        } cout<<ans+w[u]+w[v]<<'\n';
    }
}
void Mianclr(){

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c=0,T=1; cin>>c;
    while(T--){
        Mian(c);
        Mianclr();
    }
}
