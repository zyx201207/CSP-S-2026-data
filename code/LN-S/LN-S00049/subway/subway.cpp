#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int c,n,m,d,q;
int top[500010];
vector<pair<int,long long> > g[500010];
long long w[500010];
long long f[510][510];
long long dp[510][510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a;
            long long t;
            scanf("%d%lld",&a,&t);
            g[a].push_back(make_pair(i,t));
            top[a]++;
        }
    }for(int i=1;i<=n;i++){
        fill(f[i]+1,f[i]+n+1,1e18);
        f[i][i]=0;
        ///fill(dp[i]+1,dp[i]+n+1,1e18);
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<top[i];j++){
            for(int k=j+1;k<top[i];k++){
                f[g[i][j].first][g[i][k].first]=min(f[g[i][j].first][g[i][k].first],g[i][j].second+g[i][k].second);
                f[g[i][k].first][g[i][j].first]=min(f[g[i][k].first][g[i][j].first],g[i][j].second+g[i][k].second);
            }
        }
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=f[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[j][k]=min(dp[j][k],f[j][i]+f[i][k]);
            }
        }for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[j][k]=dp[j][k];
            }
        }
    }//for(int i=1;i<=n;i++){
     //   for(int j=1;j<=n;j++){
      //      printf("%lld ",f[i][j]);
      //  }puts("");
    //}
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        long long ans=w[u]+w[v];
        long long lj=1e18;
        for(int i=0;i<top[u];i++){
            for(int j=0;j<top[v];j++){
                lj=min(lj,f[g[u][i].first][g[v][j].first]+g[u][i].second+g[v][j].second);
            }
        }printf("%lld\n",ans+lj);

    }
    return 0;
}
