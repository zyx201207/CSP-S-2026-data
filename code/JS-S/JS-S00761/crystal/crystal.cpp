#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m;
long long a[N];
long long ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (long long i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    long long d=a[2]-a[1];
    bool flag=true;
    for (long long i=3;i<=n;++i)
    {
        if (a[i]-a[i-1]!=d)
        {
            flag=false;
            break;
        }
    }
    if (flag)
    {
        long long k=n/2+1;
        long long l=1,r=1;
        ans=1;
        while (m>0)
        {
            if (l==3)
            {
                l=1;
                r++;
            }
            m-=r*d;
            l++;
            if (m>=0)
                ans++;
        }
        printf("%lld\n",ans);
        return 0;
    }
    long long b[5010];
    ans=0;
    long long cnt=0;
    for (long long i=1;i<=n;++i)
    {
        for (long long j=1;j<=n;++j)
            b[j]=abs(a[i]-a[j]);
        sort(b+1,b+n+1);
        cnt=0;
        long long k=1;
        long long t=m;
        while (t>0)
        {
            t-=b[k];
            k++;
            if (t>=0)
                cnt++;
        }
        ans=max(ans,cnt);
    }
    printf("%lld\n",ans);
    return 0;
}
