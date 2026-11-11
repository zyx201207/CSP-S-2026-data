#include<bits/stdc++.h>
using namespace std;
#define int long long
int z[500010],dp[500010],dp2[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int a=0;a<n;a++){
        cin>>z[a];
    }
    sort(z,z+n);
    dp[0]=1;
    dp2[0]=m;
    int ans=1;
    for(int a=1;a<n;a++){
        int x=abs(z[a]-z[a-1]);
        while(dp2[a-1]<x*dp[a-1]){
            dp2[a-1]+=z[a-1]-z[a-dp[a-1]];
            dp[a-1]--;
        }
        dp[a]=dp[a-1]+1;
        dp2[a]=dp2[a-1]-x*dp[a-1];
        ans=max(ans,dp[a]);
    }
    //cout<<endl;
    //for(int a=0;a<n;a++)cout<<dp[a]<<' ';
    cout<<ans;
}
