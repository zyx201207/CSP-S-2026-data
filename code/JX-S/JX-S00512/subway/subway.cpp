#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=5e5+5,N=5e2+5;
const ll INF=0x7f7f7f7f7f7f7f7f;
int c,n,m,d,q,k[N];
ll w[M],t[N][N],dis[N][N];
vector<pair<int,ll>> in[M];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            in[x].push_back({i,y});
        }
    }
    memset(t,0x7f,sizeof(t));
    memset(dis,0x7f,sizeof(dis));
    for(int i=1;i<=m;i++){
        for(int x=0;x<in[i].size();x++){
            for(int y=x+1;y<in[i].size();y++){
                int u=in[i][x].first,v=in[i][y].first;
                dis[u][v]=t[u][v]=dis[v][u]=t[v][u]=in[i][x].second+in[i][y].second;
            }
        }
    }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]!=INF && dis[k][j]!=INF && dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        for(auto i:in[x]){
            for(auto j:in[y]){
                ans=min(ans,w[x]+i.second+dis[i.first][j.first]+j.second+w[y]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
