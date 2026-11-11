#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
int w[500010],dist[510][510],ti[500010][510];
vector<int> vec[500010];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(dist,0x3f,sizeof(dist));
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,t;i<=n;i++){
        cin>>t;
        for(int j=1,x,y;j<=t;j++){
            cin>>x>>y;
            ti[x][i]=y;
            for(int v:vec[x])dist[i][v]=dist[v][i]=min(dist[i][v],ti[x][v]+y);
            vec[x].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)dist[i][i]=0;
    for(int k=1;k<=n;k++)for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
    while(q--){
        int x,y,mn=inf;
        cin>>x>>y;
        for(int u:vec[x])for(int v:vec[y])mn=min(mn,ti[x][u]+ti[y][v]+dist[u][v]);
        cout<<w[x]+mn+w[y]<<"\n";
    }
    return 0;
}
