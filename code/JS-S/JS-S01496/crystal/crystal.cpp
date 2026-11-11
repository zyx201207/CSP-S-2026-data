#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,ans;
ll a[N];
ll sum[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    ll l=1;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+(i-l)*(a[i]-a[i-1]);
        while(sum[i]>m)
        {
            sum[i]-=a[i]-a[l++];
        }
        ans=max(ans,i-l+1);
    }
    printf("%lld",ans);
    return 0;
}
