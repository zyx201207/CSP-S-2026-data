#include<bits/stdc++.h>
using namespace std;

long long w[500001],dis[5001][5001],a[500001],t[500001];

int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    long long c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof(dis));
    for(long long i=1;i<=m;i++){
        cin>>w[i];
        dis[i][i]=0;
    }
    for(long long i=1;i<=n;i++){
        long long k;cin>>k;
        for(long long j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(long long j=1;j<=k;j++){
            for(long long u=j;u<=k;u++){
                dis[a[j]][a[u]]=dis[a[u]][a[j]]=min(dis[a[j]][a[u]],t[a[j]]+t[a[u]]);
            }
        }
    }
    for(long long k=1;k<=m;k++){
        for(long long i=1;i<=m;i++){
            for(long long j=1;j<=m;j++){
                dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(long long i=1;i<=q;i++){
        long long x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<'\n';
    }
    return 0;

}
