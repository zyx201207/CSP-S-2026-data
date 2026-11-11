#include<climits>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
signed int main()
{
    signed long long int L(0),n(0),J(0),z(0),j(8),l(0),m,as;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    signed long long int a[n+9],i,maxx(LONG_LONG_MIN);
    for(i=0;i<n;++i)
    {
        scanf("%lld",a+i);
        maxx=std::max(maxx,a[i]);
    }
    if(m==1)
    {
        printf("%lld",maxx);
        return 0;
    }
    maxx=a[0];
    if(m==n)
    {
        for(i=1;i<n;++i)
            maxx&=a[i];
        printf("%lld",maxx);
        return 0;
    }
    maxx=LONG_LONG_MIN;
    if(m==n-1)
    {
        for(i=0;i<n;++i)
        {
            as=(1<<30)-1;
            for(j=0;j<n;++j)
            {
                if(i==j)
                    continue;
                as&=a[i];
            }
            maxx=std::max(maxx,as);
        }
        printf("%lld",maxx);
        return 0;
    }
    maxx=LONG_LONG_MIN;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            if(i==j)
                continue;
            else
                maxx=std::max(maxx,i&j);
    printf("%lld",maxx);
    return 0;
}
