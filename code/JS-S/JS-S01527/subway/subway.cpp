#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1.414e4+5,N=505,INF=1e9+5;
int c,n,m,d,q;
int w[M],k[N],a[N][M],t[N][M];
ll dis[M][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m*(n+1);i++){
        for(int j=1;j<=m*(n+1);j++){
            if(i==j){
                continue;
            }
            dis[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            t[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<m;i++){
        for(int j=i+1;j<=m;j++){
            int x=(n+1)*(i-1),y=(n+1)*(j-1);
            for(int u=1;u<=n;u++){
                dis[x][x+u]=dis[x+u][x]=t[u][i];
                dis[y][y+u]=dis[y+u][y]=t[u][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<k[i];j++){
            int x=(n+1)*(a[i][j]-1),y=(n-1)*(a[i][j+1]-1);
            dis[x+i][y+i]=dis[y+i][x+i]=0;
        }
    }
    for(int k=1;k<=m*(n+1);k++){
        for(int i=1;i<m*(n+1);i++){
            for(int j=i;j<=m*(n+1);j++){
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[j][i]=dis[i][k]+dis[j][k];
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        if(x==y){
            cout<<0<<'\n';
            continue;
        }
        cout<<dis[(n+1)*(x-1)][(n+1)*(y-1)]+w[x]+w[y];
    }

    return 0;
}