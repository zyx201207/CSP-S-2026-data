#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500666,M=506;
int cid,n,m,d,q,w[N];
ll dp[M][M];
vector<pair<int,int>>e[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&cid,&n,&m,&d,&q);
    for (int i=1;i<=m;i++) scanf("%d",&w[i]);
    for (int i=1,k;i<=n;i++){
        scanf("%d",&k);
        for (int j=1,y,z;j<=k;j++){
            scanf("%d%d",&y,&z);
            e[y].push_back({i,z});
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dp[i][j]=1LL<<60;
    for (int i=1;i<=n;i++) dp[i][i]=0;
    for (int i=1;i<=m;i++) for (auto j:e[i]) for (auto k:e[i]){
        int x=j.first,y=k.first;
        dp[x][y]=min(dp[x][y],(ll)(j.second+k.second));
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (dp[i][k]==1LL<<60||dp[k][j]==1LL<<60) continue;
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    for (int x,y;q--;){
        scanf("%d%d",&x,&y);
        ll ans=1LL<<60;
        for (auto i:e[x]){
            for (auto j:e[y]){
                ans=min(ans,i.second+dp[i.first][j.first]+j.second);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
