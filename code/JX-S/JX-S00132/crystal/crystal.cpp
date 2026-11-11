#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],dp[500005][5],ans,sum[500005],tot[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int s=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        sum[i]=a[i+1]-a[i];
        tot[i]=tot[i-1]+sum[i];
    }
    for(int i=1;i<n;i++){
        if(dp[i-1][1]+(dp[i-1][2]+1)*sum[i]<=m){
            dp[i][1]=dp[i-1][1]+(dp[i-1][2]+1)*sum[i];
            dp[i][2]=dp[i-1][2]+1;
        }else{
            long long su=dp[i-1][1]+(dp[i-1][2]+1)*sum[i],j=i-dp[i-1][2];
            while(su>m){
                su-=tot[i]-tot[j-1];
                j++;
            }
            dp[i][1]=su;
            dp[i][2]=i-j+1;
        }
        ans=max(ans,dp[i][2]);
    }
    cout<<ans+1;
    return 0;
}
