#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int dp[100000005];
int ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        long long x=a[k];
            for(int i=0;i<=m;i++){
                dp[i]=0;
            }
        for(int i=1;i<=n;i++){
            for(int j=m;j>=abs(x-a[i]);j--){
                dp[j]=max(dp[j],dp[j-abs(x-a[i])]+1);
            }
        }
        ans=max(ans,dp[m]);
    }
    cout<<ans;
    return 0;
}
