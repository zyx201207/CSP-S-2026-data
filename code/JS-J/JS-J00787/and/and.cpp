#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],ans,dp[200009],numm[200009];
int main(){
  freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
              dp[i]=a[i];
    }
   for(int i=1; i<=n; ++i){
        numm[i]+=numm[i-1];
    for(int j=i+1; j<=n; ++j){
        if(dp[i-1]&a[j]>dp[i-1]){
            numm[i]++;
            dp[i]=dp[i-1]&a[j];
        }
    }

   }
   for(int i=1; i<=n; ++i){
        if(numm[i]==m){
          ans=max(ans,dp[i]);
        }
   }
   cout<<ans;
    return 0;
}
