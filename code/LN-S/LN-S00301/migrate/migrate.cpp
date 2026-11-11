#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll x[N];
ll dp[N][2];
ll stque[N],hh,tt;
int main(){//brute o(n^2)
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;scanf("%d%d",&c,&t);//2<=t<=1e5
    if(c==11||c==12){
        while(t--){
            ll n,d;scanf("%lld%lld",&n,&d);
            for(int i=1;i<=n;i++){
                scanf("%lld",&x[i]);
            }
            ll ans=0;
            int i=1;
            for(int j=1;j<=n;j++)dp[j][0]=dp[j][1]=0;
            dp[i][1]=1;
            hh=tt=0;stque[hh]=i;
            for(int j=i+1;j<=n;j++){
                while(x[j]-x[stque[hh]]>d){
                    hh++;
                }
                dp[j][0]=dp[stque[hh]][0]+1;
                for(int k=stque[hh];dp[k][0]<=dp[stque[hh]][0];k++){
                    dp[j][1]+=dp[k][1];
                }
                if(dp[j][1]==2){
                    ans+=(n-j+1);
                }
                stque[++tt]=j;
            }
            printf("%lld\n",ans);
        }
        return 0;
    }
    while(t--){
        ll n,d;scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        ll ans=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<=n;j++)dp[j][0]=dp[j][1]=0;
            dp[i][1]=1;
            hh=tt=0;stque[hh]=i;
            for(int j=i+1;j<=n;j++){
                while(x[j]-x[stque[hh]]>d){
                    //printf("d %d\n",stque[hh]);
                    hh++;
                }
                dp[j][0]=dp[stque[hh]][0]+1;
                for(int k=stque[hh];dp[k][0]<=dp[stque[hh]][0];k++){
                    dp[j][1]+=dp[k][1];
                }
                if(dp[j][1]==2){
                    ans++;
                }
                stque[++tt]=j;
//printf("debug (%d,%d)->%d,%d\n",i,j,dp[j][0],dp[j][1]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
