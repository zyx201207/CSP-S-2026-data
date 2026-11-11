#include <bits/stdc++.h>
using namespace std;
#define int long long
long long n,m;
long long a[5000007];
long long sum[5000007];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n==1){
        cout<<1<<'\n';
        return 0;
    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=(sum[i-1]+a[i]);
    }
    long long ans=-114514;
    for(long long i=n;i>1;i--){
        //cout<<i<<'\n';
        long long l=1,r=i-1;
        while(l<=r){
            int mid=(l+r)>>1;
            int add=-(sum[i-1]-sum[mid-1]);
            add+=(a[i]*(i-mid));
            //cout<<mid<<' '<<add<<'\n';
            if(add>m) l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}
