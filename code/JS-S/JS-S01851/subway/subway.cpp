#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e18;
long long w[500005];
long long k[500005];
long long a[1005][1005],t[1005][1005],dis[1005][1005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=0;i<=1003;i++){
        for(long long j=0;j<=1003;j++){
            dis[i][j]=MAXN;
        }
    }
    for(long long i=1;i<=n;i++){
        cin>>k[i];
        for(long long j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
        for(long long k1=1;k1<=k[i];k1++){
            for(long long k2=1;k2<=k[i];k2++){
                if(k1==k2){
                    dis[a[i][k1]][a[i][k2]]=0;
                     dis[a[i][k2]][a[i][k1]]=0;
                }
                else{
                        dis[a[i][k1]][a[i][k2]]=min(dis[a[i][k1]][a[i][k2]],t[i][k1]+t[i][k2]);
                         dis[a[i][k2]][a[i][k1]]=min(dis[a[i][k2]][a[i][k1]],t[i][k2]+t[i][k1]);
                }
            }
        }
    }
    for(long long i=1;i<=m;i++){
        for(long long j=1;j<=m;j++){
            for(long long k1=1;k1<=m;k1++){
                if(i!=j && j!=k1){
                    dis[i][j]=min(dis[i][j],dis[i][k1]+dis[k1][j]);
                }
            }
        }
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}


