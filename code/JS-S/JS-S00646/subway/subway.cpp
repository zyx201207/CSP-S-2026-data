#include<bits/stdc++.h>
using namespace std;
const int MAXM=405;
const int MAXN=505;
int c,n,m,d,q;
int w[MAXM];
vector<pair<int,int>>e[MAXN];
int dp[MAXM][MAXM];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    memset(dp,0x3f3f3f3f,sizeof(dp));
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    for(int i=1;i<=m;i++)dp[i][i]=0;
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int l=1;l<=k;l++){
            int a,t;
            scanf("%d%d",&a,&t);
            e[i].push_back({a,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int l=0;l<e[i].size();l++){
            for(int j=0;j<l;j++){
                dp[e[i][l].first][e[i][j].first]=e[i][l].second+e[i][j].second;
                dp[e[i][j].first][e[i][l].first]=dp[e[i][l].first][e[i][j].first];
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int l=1;l<i;l++){
            for(int k=1;k<=m;k++){
                dp[i][l]=min(dp[i][l],dp[i][k]+dp[k][l]);
                dp[l][i]=dp[i][l];
            }
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",w[x]+w[y]+dp[x][y]);
    }
    return 0;
}