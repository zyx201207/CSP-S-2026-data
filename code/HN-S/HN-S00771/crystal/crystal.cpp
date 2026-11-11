#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m;
long long a[N];
long long sum[N];
long long ans;
bool check(long long l,long long r){
    return ((r-l+1)*a[r]-(sum[r]-sum[l-1]))<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        long long l=i,r=n,id=i-1;
        while(l<=r){
            long long mid=(l+r)/2;
            if(check(i,mid))l=mid+1,id=mid;
            else r=mid-1;
        }
        ans=max(ans,id-i+1ll);
    }
    cout<<ans<<endl;
    return 0;
}