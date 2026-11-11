#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,b[500005],l,r,jl,mid,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
        l=1,r=i,jl=0;
        while(l<=r){
            mid=(l+r)/2;
            if(mid*a[i]-b[i]+b[i-mid-1]<=m)jl=max(jl,mid),l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,jl);
    }
    cout<<ans;
}
