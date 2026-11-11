#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],u,v;
long long dist[500005];
bool vis[500005];
vector<pair<int,int>>g[505];
void dijkstra(int u,int v){
    for(int i=1;i<=n;i++)dist[i]=2e9,vis[i]=0;
    dist[u]=w[u];
    for(int i=1;i<=n;i++){
        int u=-1,di=2e9;
        for(int i=1;i<=n;i++){
            if(vis[i]&&(u==-1||dist[i]<di)){
                di=dist[i];
                u=i;
            }
        }
        if(u==-1||dist[u]==2e9)return;
        for(int i=1;i<=n;i++){

        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            g[i].push_back({a,t});
        }
        cin>>u>>v;
        dijkstra(u,v);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
