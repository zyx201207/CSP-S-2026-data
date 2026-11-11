#include<bits/stdc++.h>
using namespace std;
long long n,a[500002],m;
bool check(long long l,long long r)
{
    long long ans=0;
    for(long long i=l;i<=r-1;i++)
    {
        ans+=a[r]-a[i];
        if(ans>m)return false;
    }
    return true;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    long long ls_left=1;
    long long ans=0;
    for(long long i=1;i<=n;i++)
    {
        long long l=ls_left,r=i-1,mid;
        while(l+1<=r)
        {
            mid=(l+r)>>1;
            if(check(mid,i))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        ans=max(ans,(long long)(i-l+1));
        ls_left=l;
    }
    printf("%lld",ans);
    return 0;
}
