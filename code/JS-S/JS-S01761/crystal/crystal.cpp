#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,a[N],ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int sum=0,l=1,r=0;
    for(int i=2;i<=n;++i)
    {
        r++;
        int cnt=r-l+1;
        sum+=cnt*(a[i]-a[i-1]);
        if(sum>m)
        {
            while(l<=r&&sum>m)
                sum-=a[i]-a[l],l++;
        }
        ans=max(ans,r-l+1);
    }
    printf("%lld",ans+1);
    return 0;
}
