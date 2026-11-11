#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long ans,n,m,a[N],sum[N];
bool check(long long mid){
    for(long long i=1;i+mid-1<=n;i++){
        long long x=i+mid-1;
        if(1ll*a[x]*mid-(sum[x]-sum[i-1])<=m)return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    long long l=0,r=n;
    while(l<=r){
        long long mid=(l+r)/2;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<'\n';
    return 0;
}
