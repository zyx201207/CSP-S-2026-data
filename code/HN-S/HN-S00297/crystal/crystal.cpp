#include<bits/stdc++.h>
using int_64=long long;

constexpr int N=5e5;

int_64 a[N+5],sum[N+5];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    // freopen("crystal.log","w",stderr);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);

    int n;int_64 m;
    std::cin>>n>>m;

    for(int i=1;i<=n;++i)std::cin>>a[i];
    std::sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];

    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int l=1,r=i,p=i;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if((a[i]*(i-mid+1))-(sum[i]-sum[mid-1])<=m)r=mid-1,p=mid;
            else l=mid+1;
        }
        // std::cerr<<i<<' '<<p<<'\n';
        ans=std::max(ans,i-p+1);
    }
    std::cout<<ans<<'\n';
}