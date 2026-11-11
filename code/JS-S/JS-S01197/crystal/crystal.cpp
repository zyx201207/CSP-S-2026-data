#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s,a[500010],b[500010],sum[500010];
bool solve(int t)
{
    for(int i=t;i<=n;i++)
        if(a[i-t+1]*t-sum[i]+sum[i-t]<=m)return 1;
    return 0;
}
void ssort(int l,int r)
{
    if(l>=r)return;
    int mid=(l+r)>>1;
    ssort(l,mid);
    ssort(mid+1,r);
    int i=l,j=mid+1;
    for(int t=l;t<=r;t++)
    {
        if(j>r||i>mid)
        {
            if(j>r)b[t]=a[i++];
            else b[t]=a[j++];
        }
        else
        {
            if(a[i]>a[j])b[t]=a[i++];
            else b[t]=a[j++];
        }
    }
    for(int i=l;i<=r;i++)
        a[i]=b[i];
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    ssort(1,n);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    int l=1,r=n;
    for(;;)
    {
        int mid=(l+r)>>1;
        if(mid<=n&&solve(mid))
        {
            s=mid;
            l=mid+1;
        }
        else r=mid-1;
        if(l>r)break;
    }
    printf("%lld\n",s);
    return 0;
}
