#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,M=500010;
ll c,n,m,d,q;
ll w[M];
int k[N];
vector<int> tog[M];
vector<ll> sco[M];
ll dist[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            ll a,t;
            cin>>a>>t;
            tog[a].push_back(i);
            sco[a].push_back(t);
        }
    }
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=n;i++) dist[i][i]=0;
    for(int i=1;i<=m;i++){
        int sz=tog[i].size();
        for(int u=0;u<sz;u++){
            for(int v=u+1;v<sz;v++){
                dist[tog[i][u]][tog[i][v]]=min(dist[tog[i][u]][tog[i][v]],sco[i][u]+sco[i][v]);
            }
        }
    }
    for(int u=1;u<=n;u++)for(int v=u+1;v<=n;v++) dist[v][u]=dist[u][v];
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        ll ans=0x3f3f3f3f3f3f3f3f;
        int us=tog[u].size(),vs=tog[v].size();
        for(int st=0;st<us;st++){
            for(int en=0;en<vs;en++){
                ans=min(ans,sco[u][st]+sco[v][en]+dist[tog[u][st]][tog[v][en]]);
            }
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}