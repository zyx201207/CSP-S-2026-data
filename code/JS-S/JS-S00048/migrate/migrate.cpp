#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
long long dp[maxn][maxn],be_ans[maxn][maxn],c,T,ans,n,d,a[maxn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while(T--){
        ans=0;
        memset(dp,0x3f3f3f3f,sizeof(dp));
        memset(be_ans,0,sizeof(be_ans));
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(d>=a[j]-a[i]){
                    dp[i][j]=1;
                    dp[j][i]=1;
                }
                if(i==j){
                    dp[i][j]=0;
                    dp[j][i]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=i+1;k<j;k++){
                   dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        //cout<<1<<endl;
    /*for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%d %d %d\n",i,j,dp[i][j]);
            }
        }*/
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=i+1;k<j;k++){
                   if(dp[i][j]==dp[i][k]+dp[k][j]){
                        be_ans[i][j]++;

                   }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(be_ans[i][j]==2) ans++;
            }
        }
        printf("%lld\n",ans);
    }



    return 0;
}
