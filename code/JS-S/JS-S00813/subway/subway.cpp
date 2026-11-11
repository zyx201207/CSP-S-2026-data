#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+10;
const int inf=-1;
int c,n,m,d,q;
int w[N];
ll a[501][N];
ll g[N][N];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
    cin>>w[i];
    for(int j=1;j<=n;j++)a[j][i]=inf;
    for(int j=1;j<=m;j++){
        g[i][j]=inf;
    }
}
for(int i=1;i<=n;i++){
    int k;cin>>k;
    for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            cin>>a[i][x];
    }
    for(int u=1;u<=k;u++){
        for(int v=u+1;v<=k;v++){
                if(a[i][u]==inf||a[i][v]==inf)continue;
            if(g[u][v]==-1||g[u][v]>a[i][u]+a[i][v])g[u][v]=a[i][u]+a[i][v],g[v][u]=a[i][u]+a[i][v];
        }
    }
}
for(int k=1;k<=m;k++){
for(int i=1;i<=m;i++){
    for(int j=1;j<=m;j++){
        if(g[i][k]!=inf&&g[j][k]!=inf)if(g[i][j]>g[i][k]+g[j][k])g[i][j]=g[i][k]+g[j][k];
    }
}
}

for(int r=1;r<=q;r++){
    int x,y;
    cin>>x>>y;
    cout<<w[x]+w[y]+g[x][y]<<'\n';
    }
return 0;
}

