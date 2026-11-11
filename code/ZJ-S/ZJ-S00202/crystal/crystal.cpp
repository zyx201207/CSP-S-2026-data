#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
#ifndef zzr
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
#endif 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    vector<int>sum(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
    int res=0;
    for(int i=1;i<=n;++i)
    {
        int l=1,r=i;
        int ans=i+1;
        auto check=[&](int mid)->bool
        {
            int cnt=i-mid+1;
            return sum[i]-sum[mid-1]+m>=cnt*a[i];
        };
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid))ans=mid,r=mid-1;
            else l=mid+1;
        }
        // cerr<<i<<' '<<ans<<'\n';
        res=max(res,i-ans+1);
    }
    cout<<res<<'\n';
}