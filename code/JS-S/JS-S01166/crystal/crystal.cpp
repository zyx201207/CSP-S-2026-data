#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],dp[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m,Max=0;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
        //cout<<b[i]<<" ";
    }
    //cout<<endl;
    dp[1]=1;
    for(ll i=2;i<=n;i++){
        ll ans=b[i-1]-b[i-1-dp[i-1]+1]-(i-1-dp[i-1])*(a[i-1]-a[i-1-dp[i-1]+1])+dp[i-1]*(a[i]-a[i-1]);
        if(ans<=m)dp[i]=dp[i-1]+1;
        else{
            ll cnt=dp[i-1];
            while(ans>m){
                ans=ans-(a[i]-a[i-cnt]);
                cnt--;
            }
            dp[i]=cnt+1;
        }
    }
    for(int i=1;i<=n;i++){
        //cout<<dp[i]<<" ";
        Max=max(Max,dp[i]);
    }
    cout<<Max;
    return 0;
}
