#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long f[505][505][505],w[500005];
vector<pair<int,long long>> p[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(long long j=1;j<=k;j++){
            int a;
            long long t;
            scanf("%d%lld",&a,&t);
            p[a].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            f[0][i][j]=LONG_LONG_MAX/2;
    }
    for(int i=1;i<=n;i++)
        f[0][i][i]=0;
    for(int i=1;i<=m;i++){
        for(pair<int,long long> x:p[i]){
            for(pair<int,long long> y:p[i]){
                int u=x.first,v=y.first;
                if(u!=v)
                    f[0][u][v]=min(f[0][u][v],x.second+y.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                f[k][i][j]=min(f[k-1][i][k]+f[k-1][k][j],f[k-1][i][j]);
        }
    }
    while(q--){
        int x,y;
        long long ans=LONG_LONG_MAX;
        scanf("%d%d",&x,&y);
        for(pair<int,long long> i:p[x]){
            for(pair<int,long long> j:p[y]){
                int u=i.first,v=j.first;
                ans=min(ans,f[n][u][v]+i.second+j.second);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
