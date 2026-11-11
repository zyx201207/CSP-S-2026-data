#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long N=5e5+10;
long long a[N],sum[N];
long long check(long long x){
    for(long long i=x;i<=n;i++){
        long long needm=a[i]*x-(sum[i]-sum[i-x]);
        if(needm<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    long long l=1,r=n,ans=0;
    while(l<=r){
        long long mid=(l+r)/2;
        long long t=check(mid);
        if(t==1){
            ans=max(ans,mid);
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
