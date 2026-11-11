#include<bits/stdc++.h>
#define int long long
using namespace std;
int cc,T,n,d,a[2000005],dp[305],c[305],ans;
void solve(){
    ans=0;
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        memset(c,0,sizeof(c));
        memset(dp,0x3f,sizeof(dp));
        dp[i]=0;
        c[i]=1;
        for(int j=i+1;j<=n;j++){
            int cnt=0;
            for(int k=j;k>=1;k--){
                if(abs(a[j]-a[k])>d)break;
                if(dp[k]+1<dp[j]){
                    cnt=0;
                    dp[j]=dp[k]+1;
                }
                if(dp[j]==dp[k]+1)cnt+=c[k];
            }
            ans+=(cnt==2);
            c[j]=cnt;
        }
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&cc,&T);
    while(T--)solve();
    return 0;
}
