#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500010],sum[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;++i)
    {
        //sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
        for(int j=i-1;j>=0;--j)
        {
            long long tmp=(i-j)*a[i]-(sum[i]-sum[j]);
            if(tmp<=m)
            {
                ans=max(ans,(i-j)*1ll);
            }
            else
            {
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
