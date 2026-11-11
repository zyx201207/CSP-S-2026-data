#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    if(n==m)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans&=a[i];
        }
    }
    else if(m==n-1)
    {
        n--;
        ans=a[1];
        for(long long i=2;i<=n;i++)
        {
            ans&=a[i];
        }
    }
    else
    {
        sort(a+1,a+n+1);
        ans=a[n];
        m--;
        for(long long i=n-1;i>=1&&m;i--,m--)
        {
            ans&=a[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}