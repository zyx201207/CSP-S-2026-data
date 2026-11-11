#include<climits>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
signed int main()
{
    signed long long int L(0),n(0),J(0),z(0),j(8),l(0),len(0),lo,i,ans(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    char c[5000000],ch;
    if(n==1)
    {
        putchar('0');
        return 0;
    }
    if(n==2)
    {
        signed long long int a,b;
        char c,d;
        scanf("%lld %c\n%lld %c",&a,&c,&b,&d);
        if(c==d)
            putchar('0');
        else
            printf("%lld",std::min(a,b));
        return 0;
    }
    for(i=0;i<n;++i)
    {
        scanf("%lld %c",&lo,&ch);
        memset(c+len+1,ch,lo);
        len+=lo;
    }
    if(len%2)
        for(i=1,j=len;i!=((len+1)/2);++i,--j)
            ans+=c[i]!=c[j];
    else
        for(i=1,j=len;i<j;++i,--j)
            ans+=c[i]!=c[j];
    printf("%lld",ans);
    return 0;
}
