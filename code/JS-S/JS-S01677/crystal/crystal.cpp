#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],q[500005];
bool check(long long num)
{
    if(num==1)
    {
        return 1;
    }
    else if((num-1)*a[num]-q[num-1]<=m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n;
    bool f1=1,f2=1;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]!=i)
        {
            f1=0;
        }
        if(i>=3)
        {
            if(a[i]-a[i-1]!=a[i-1]-a[i-2])
            {
                f2=0;
            }
        }

    }
    if(f1)
    {
        long long num=0;
        while((num+1)*num<=2*m)
        {
            num++;
        }
        printf("%lld",num);
    }
    else if(f2)
    {
        long long k=abs(a[2]-a[1]),num=0;
        while((num+k)*num<=2*m*k)
        {
            num+=k;
        }
        printf("%lld",num/k);
    }
    else
    {
        long long minn=1e9;
        sort(a+1,a+n+1);
        q[1]=a[1];
        for(int i=2;i<=n;i++)
        {
            q[i]=q[i-1]+a[i];
            minn=min(minn,(a[i]-a[i-1]));
        }
        long long l=1,r=n,mid,ans=0;
        while(l<=r)
        {
            mid=(r-l)/2+l;
            if(check(mid))
            {
                ans=max(mid,ans);
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        printf("%lld",ans);
    }
    return 0;
}
