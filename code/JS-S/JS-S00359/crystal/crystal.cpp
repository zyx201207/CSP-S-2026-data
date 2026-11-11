#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000010];
__int128 dp[1000010]={0};
bool ck(int l){
    for(int i=l;i<=n;i++){
        if((dp[i]-dp[i-l]-(i-l)*(a[i]-a[i-l]))<=m){
            return true;
        }
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    // cout<<m;
    for(int i=1;i<=n;i++)cin>>a[i];
    stable_sort(a+1,a+n+1);
    dp[1]=0;
    for(int i=1;i<=n;i++){
        __int128 d=a[i]-a[i-1];
        dp[i]=dp[i-1]+(d*(i-1));
    }
    if(dp[n]<=m){
        cout<<n;
        return 0;
    }
    int lft=1,rgt=n;
    int ans=0;
    while(lft<=rgt){
        // cout<<ans<<'\n';
        int mid=(lft+rgt)/2;
        if(ck(mid))ans=mid,lft=mid+1;
        else rgt=mid-1;
    }
    cout<<ans;
    return 0;
}