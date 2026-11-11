#include<bits/stdc++.h>
using namespace std;
#define int long long
#define O_ return
#define my cout
#define touhou <<
#define tiny_game -1
const int N=2e6+6,M=5e3+3,inf=0x3f3f3f3f3f3f3f3f;
int c,t,n,d,a[N],dp[M][M],ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        if(n<=3){
            printf("0\n");
            continue;
        }if(c==11||c==12){
            if((a[2]-a[1])*3<=d||(a[2]-a[1])*2>d)printf("0\n");
            else printf("%lld\n",n-3);
        }else{
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dp[i][j]=-2*inf;
            for(int i=1;i<=n;i++){
                dp[i][i]=0;
                for(int j=i+1;a[j]-a[i]<=d&&j<=n;j++){
                    for(int k=1;k<=i;k++){
                        if(dp[j][k]==dp[i][k]+1)ans++,dp[j][k]=dp[i][k]+1+inf;
                        else if(dp[j][k]==dp[i][k]+1+inf)ans--,dp[j][k]==dp[i][k]+1-inf;
                        else if(dp[j][k]==-2*inf)dp[j][k]=dp[i][k]+1;
                    }
                }
            }printf("%lld\n",ans);
        }
    }
    O_ 0;
    http://thenv.me
    my touhou tiny_game;
    O_ 0;
}//好鸟,不会 8pts
