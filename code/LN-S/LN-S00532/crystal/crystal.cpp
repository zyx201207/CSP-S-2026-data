#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long c[500005];
long long ans=1;
bool cmp(long long a,long long b)
{
    return a<b;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    int f=0,f1=0;
    long long gl=0;
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]!=i) f=1;
        if(i==2) gl=a[2]-a[1];
        if(i>=2&&a[i]-a[i-1]!=gl) f1=1;
    }
    sort(a+1,a+1+n,cmp);
    if(f==0)
    {
        for(long long i=1;i<=n;i++)
        {
            if(m<i)
            {
                break;
            }
            m-=i;
            ans++;
        }
        cout<<ans;
        return 0;
    }
    if(f1==0)
    {
        for(long long i=1;i<=n-1;i++)
        {
            if(m<i*abs(gl))
                break;
            m-=i*abs(gl);
            ans++;
        }
        cout<<ans;
        return 0;
    }
    for(long long i=1;i<=n;i++)
    {
        c[i]=a[i]-a[1];
    }
    for(long long i=2;i<=n;i++)
    {
        long long num=0,j=i;
        for(j=i;j>=1;j--)
        {
            long long ad=a[i]-a[j];
            if(num+ad>m) break;
            num+=ad;
        }
        ans=max(ans,i-j);
    }
    printf("%lld",ans);
    return 0;
}
