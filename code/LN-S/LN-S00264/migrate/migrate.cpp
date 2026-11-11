#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,a[2000001];
ll dp[1001][1001],vis[1001][1001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for(int i=1;i<=t;i++){
        ll ans=0;
        scanf("%lld%lld",&n,&d);
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[j]);
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[j][k]=1e18;
                vis[j][k]=0;
                ll u=abs(a[k]-a[j]);
                if(u<=d){
                    dp[j][k]=0;
                    vis[j][k]=1;
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int s=j+1;s<=n;s++){
                for(int k=j+1;k<s;k++){
                    dp[j][s]=min(dp[j][s],dp[j][k]+dp[k][s]+1);
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int s=j+1;s<=n;s++){
                for(int k=j+1;k<s;k++){
                    if(dp[j][s]==dp[j][k]+dp[k][s]+1){
                        ll x=vis[j][k],y=vis[k][s];
                        vis[j][s]+=x*y;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int s=j+1;s<=n;s++){
                if(vis[j][s]==2){
                    ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
