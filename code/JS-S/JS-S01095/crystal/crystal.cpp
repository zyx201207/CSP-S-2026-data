#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,ans,a[N],b[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(ll i=1,j=1,sum=0;i<=n;i++)
    {
        sum+=(a[i]-a[i-1])*(i-j);
        while(j<i&&sum>m)
        {
            sum-=(a[i]-a[j]);
            j++;
        }
        ans=max(ans,i-j+1);
    }
    printf("%lld\n",ans);
    return 0;
}
