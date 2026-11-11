#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5,Q=1e5+5,INF=LONG_MAX/10;
int c,n,m,d,q;
int a[N],t[N],w[M];
int dis[N][N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in" ,"r",stdin );
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            dis[i][j]=INF;
    for(int i=1;i<=m;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)cin>>a[j]>>t[j];
        for(int u=1;u<=k;u++){
            for(int v=1;v<=k;v++){
                if(u==v)continue;
                dis[a[u]][a[v]]=min(dis[a[u]][a[v]],t[u]+t[v]);
            }
        }
    }
    for(int i=1;i<=m;i++)
        for(int k=1;k<=m;k++)
            for(int j=1;j<=m;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<'\n';
    }
    return 0;
}
