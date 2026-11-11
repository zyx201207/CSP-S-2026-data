#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1000000],sum[1000000],bans;
int check(int l,int r){
    return (a[r]*(r-l+1)-(sum[r]-sum[l-1]))<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i,ans=0;
        while(l<r){
            int mid=l+(r-l)/2;
            if(check(mid,i)){
                r=mid;
                ans=max(ans,i-mid+1);
            }
            else{
                l=mid+1;
            }
        }
        bans=max(ans,bans);
    }
    cout<<max(bans,1ll);
}