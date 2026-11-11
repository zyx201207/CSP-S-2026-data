//100pts 15:20
#include<bits/stdc++.h>
#define ll long long
const int N=5e2+5,M=5e5+5;
using namespace std;
int cc,n,m,d,Q;
ll dis[N][N];
int w[M];
struct node{
    int x;//na tiao di tie
    int t;//time
};
node c[M][22];
int l[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>cc>>n>>m>>d>>Q;
    memset(dis,0x3f,sizeof dis);
    for (int i=1;i<=n;i++) dis[i][i]=0;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        for (int j=1;j<=k;j++){
            int x,t;
            cin>>x>>t;
            c[x][++l[x]]={i,t};
        }
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=l[i];j++){
            for (int k=j+1;k<=l[i];k++){
                int x=c[i][j].x,y=c[i][k].x;
                dis[x][y]=min(dis[x][y],0ll+c[i][j].t+c[i][k].t);
                dis[y][x]=dis[x][y];
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int k=1;k<=n;k++){
            for (int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while (Q--){
        int u,v;
        cin>>u>>v;
        ll ans=1e18;
        for (int i=1;i<=l[u];i++){
            for (int j=1;j<=l[v];j++){
                int x=c[u][i].x,y=c[v][j].x;
                ans=min(ans,w[u]+w[v]+dis[x][y]+c[u][i].t+c[v][j].t);
            }
        }
        cout<<ans<<'\n';
    }
}
