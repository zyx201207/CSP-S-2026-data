#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m;
int l,r;
int cost;
int ans;
int a[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    l=1;
    for(r=1;r<=n;r++)
    {
        cost+=(a[r]-a[r-1])*(r-l);
        while(cost>m)
        {
            cost-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    printf("%lld",ans);
    return 0;
}
