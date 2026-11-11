#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long c,n,m,d,q,w[500005],t_all[500005][25],dp[505][505],ans=0x3f3f3f3f;

vector<long long> fa[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));

    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);

    for (int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }

    for (int i=1;i<=n;i++){
        dp[i][i]=0;
        long long k;
        scanf("%lld",&k);
        for (int j=1;j<=k;j++){
            long long a,t;
            scanf("%lld%lld",&a,&t);
            t_all[a][i] = t;
            for (auto it:fa[a]){
                dp[i][it] = min(dp[i][it],t_all[a][i]+t_all[a][it]);
                dp[it][i] = dp[i][it];
            }
            fa[a].push_back(i);
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            for (int k=1;k<=n;k++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    for (int i=1;i<=q;i++){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        ans = 0x3f3f3f3f;
        for (auto u:fa[x]){
            for (auto v:fa[y]){
                ans = min(ans,dp[u][v]+t_all[x][u]+t_all[y][v]+w[x]+w[y]);
            }
        }

        printf("%lld\n",ans);
    }
	return 0;
}
