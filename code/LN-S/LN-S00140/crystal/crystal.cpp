#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<climits>
signed int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    signed long long int ln(0),s(0),z(1),j(4),l(0),n,i,m,as,ans(LONG_LONG_MIN),tmp,c;
    bool bo(true);
    scanf("%lld%lld",&n,&m);
    signed long long int a[n+9]={};
    scanf("%lld%lld",a+1,a+2);
    c=a[2]-a[1];
    for(i=3;i<=n;++i)
    {
        scanf("%lld",a+i);
        if(a[i]-a[i-1]!=c)
            bo=false;
    }
    if(bo)
    {
        for(i=1;i<=n;++i)
        {
            tmp=a[i]*i-(a[1]+a[i])*i/2;
            if(tmp>m)
                break;
        }
        --i;
        printf("%lld",i);
        return 0;
    }
    std::sort(a+1,a+n+1);
    for(i=1;i<=n;++i)
    {
        as=1;
        tmp=0;
        for(j=i-1;j;--j)
            if(tmp+a[i]-a[j]>m)
                break;
            else
            {
                ++as;
                tmp+=a[i]-a[j];
            }
        ans=std::max(ans,as);
    }
    printf("%lld",ans);
    return 0;
}
