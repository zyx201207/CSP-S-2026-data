#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,mid,ans;
long long a[500002];
bool check(long long x)
{
    long long sum=0,ans1=0;
    long long a1=a[x];
    for(int i=x;i>=1;i--)
    {
        if(a[i]<=a1)
        {
            if(sum+a1-a[i]>m)
            {
                break;
            }
            sum+=a1-a[i];
            ans1++;
        }
    }
    if(ans1>ans)
    {
        ans=ans1;
        return true;
    }
    else
    {
        return false;
    }
}
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
    l=1;
    r=n;
    while(l<r)
    {
        mid=(l+r)/2;
        if(check(mid)==true)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    printf("%lld",ans);
    return 0;
}
