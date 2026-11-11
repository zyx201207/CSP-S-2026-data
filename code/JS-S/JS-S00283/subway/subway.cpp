#include<bits/stdc++.h>
using namespace std;
long long C,D,n,m,q,K,w[500005],sz[500005],u,v,nw,nw1,val,dis[505][505],ans;
vector<pair<long long,long long>>b[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>D>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>K;
        for(int j=1;j<=K;j++){
            cin>>nw>>val;sz[nw]++;
            b[nw].push_back({i,val});
        }
        for(int j=1;j<=n;j++)dis[i][j]=1e18;
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<sz[i];j++){
            for(int k=j+1;k<sz[i];k++){
                u=b[i][j].first,v=b[i][k].first;
                dis[u][v]=dis[v][u]=min(dis[u][v],b[i][j].second+b[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)if(dis[i][k]<1e17)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        cin>>u>>v;ans=1e18;
        for(int j=0;j<sz[u];j++){
            for(int k=0;k<sz[v];k++){
                ans=min(ans,dis[b[u][j].first][b[v][k].first]+b[u][j].second+b[v][k].second+w[u]+w[v]);
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
