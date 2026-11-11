#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x7fffffff
int c,n,m,d,q;
const int maxn=5e5+5;
ll w[maxn],dp[405][405],a[maxn],t[maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
        for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                    dp[i][j]=inf;
            }
        }
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            for(int j=1;j<=x;j++){
                scanf("%lld%lld",&a[j],&t[j]);
            }
            for(int j=1;j<=x;j++){
                for(int k=j+1;k<=x;k++){
                    dp[a[j]][a[k]]=min( dp[a[j]][a[k]],t[j]+t[k]);
                    dp[a[k]][a[j]]=min( dp[a[k]][a[j]],t[j]+t[k]);
                    //dp[a[j]][a[k]]=dp[a[k]][a[j]]=t[j]+t[k];
                }
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=m;k++){
                    if(dp[j][i]+dp[i][k]<dp[j][k]){
                        dp[j][k]=dp[j][i]+dp[i][k];
                    }
                }
            }
        }
        for(int i=1;i<=q;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%lld\n",dp[x][y]+w[x]+w[y]);
        }
    return 0;
}
