#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
using ll=long long;
const int N=500009;
const ll linf=1e18;
int c,m,n,d,q,w[N];
vector<pair<int,int> > ts[N];
ll dis[509][509];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // auto now=clock();
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        for(int j=1;j<=k;j++){
            int a,t; cin>>a>>t;
            ts[a].pb({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dis[i][j]=linf;
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<ts[i].size();j++){
            for(int k=j+1;k<ts[i].size();k++){
                int u=ts[i][j].first,v=ts[i][k].first;
                ll w=ts[i][k].second+ts[i][j].second;
                dis[u][v]=min(dis[u][v],w);
                dis[v][u]=min(dis[v][u],w);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y; cin>>x>>y;
        ll ans=linf;
        for(auto u:ts[x]){
            for(auto v:ts[y]){
                ans=min(ans,u.second+v.second+dis[u.first][v.first]);
            }
        }   
        cout<<ans+w[x]+w[y]<<"\n";
    }
    // cerr<<1.0*(clock()-now)/CLOCKS_PER_SEC<<"\n";
    return 0; 
}