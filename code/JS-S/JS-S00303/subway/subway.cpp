#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define m_p make_pair
#define P pair<int,int>
#define lowbit(x) (x&(-x))
#define fr first
#define sc second
typedef long long ll;
ll d[505][505];
ll w[500005];
vector<pair<int,ll> > g[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,D,q;cin>>c>>n>>m>>D>>q;
    for(int i=0;i<n+2;i++){
        for(int j=0;j<n+2;j++) d[i][j]=1e18;
        d[i][i]=0;
    }
    for(int i=0;i<m;i++) cin>>w[i];
    for(int i=0;i<n;i++){
        int k;cin>>k;
        while(k--){
            int u;ll t;cin>>u>>t;u--;
            g[u].pb({i,t});
        }
    }
    for(int x=0;x<m;x++){
        for(int i=0;i<g[x].size();i++) for(int j=i+1;j<g[x].size();j++){
            int u=g[x][i].fr,v=g[x][j].fr;ll t=g[x][i].sc+g[x][j].sc;
            d[u][v]=min(d[u][v],t);
            d[v][u]=min(d[v][u],t);
        }
    }
    for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    while(q--){
        int u,v;cin>>u>>v;
        u--;v--;
        ll ans=1e18;
        for(int i=0;i<g[u].size();i++){
            int a=g[u][i].fr;
            for(int j=0;j<g[v].size();j++){
                int b=g[v][j].fr;
                ll t=d[a][b]+g[u][i].sc+g[v][j].sc;
                ans=min(ans,t);
            }
        }
        ans+=w[u]+w[v];
        cout<<ans<<'\n';
    }
    return 0;
}