#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[50005];
int k[50005];
vector<int>a[1005];
int yi[50005],er[50005];
int dist[3005][3005];
int dis[50005],vis[50005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                dist[i][j]=1e15;
            }
            dist[i][i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>yi[j]>>er[j];
            }
            for(int j=1;j<=k[i];j++){
                for(int j2=1;j2<=k[i];j2++){
                    if(j==j2)continue;
                    dist[yi[j]][yi[j2]]=min(dist[yi[j]][yi[j2]],er[j]+er[j2]);
                }
            }
        }
        for(int k2=1;k2<=m;k2++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k2]+dist[k2][j]);
                }
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+dist[x][y]<<"\n";
        }
    return 0;
}
