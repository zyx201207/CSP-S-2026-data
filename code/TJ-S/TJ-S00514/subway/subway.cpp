#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500,M=500000,D=20;
int c,n,m,d,q;
vector<int>v[N+3],t[N+3];
int w[M+5],k[N+5],g[M+5],a[M+3][D+3][2];
ll dist[N+3][N+3];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for (int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for (int j=1;j<=k[i];j++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[i].push_back(x);
            t[i].push_back(y);
            a[x][++g[x]][0]=i;
            a[x][g[x]][1]=y;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            dist[i][j]=1e18;
        }
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=g[i];j++){
            for (int k=j+1;k<=g[i];k++){
                //cout<<i<<" "<<j<<" "<<k<<" "<<a[i][j][0]<<" "<<a[i][k][0]<<" "<<dist[a[i][j][0]][a[i][k][0]]<<"\n";
                dist[a[i][j][0]][a[i][k][0]]=dist[a[i][k][0]][a[i][j][0]]=min(dist[a[i][j][0]][a[i][k][0]],(ll)a[i][j][1]+a[i][k][1]);
            }
        }
    }/*
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<dist[i][j]<<" ";
        }cout<<"\n";
    }*/
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }
    for (int i=1;i<=n;i++)dist[i][i]=0;/*
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<dist[i][j]<<" ";
        }cout<<"\n";
    }*/
    for (int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans=1e18;
        for (int j=1;j<=g[x];j++){
            for (int k=1;k<=g[y];k++){
                //cout<<x<<" "<<y<<" "<<j<<" "<<k<<" "<<a[x][j][0]<<" "<<a[y][k][0]<<"\n";
                ans=min(ans,(ll)a[x][j][1]+a[y][k][1]+dist[a[x][j][0]][a[y][k][0]]);
            }
        }
        ans+=(ll)w[x]+w[y];
        cout<<ans<<"\n";
    }
    return 0;
}
