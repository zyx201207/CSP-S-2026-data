#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
    bool flag=false;
    char c=getchar();
    while (!isdigit(c))
    {
        if (c=='-')
            flag=true;
        c=getchar();
    }
    long long ans=0;
    while (isdigit(c))
    {
        ans=ans*10+c-48;
        c=getchar();
    }
    return flag?-ans:ans;
}
void write(const long long x)
{
    if (x>9)
        write(x/10);
    putchar(x%10+48);
    return;
}
long long a[500001],sum[500001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    const long long n=read(),m=read();
    for (long long i=0;i<n;++i)
        a[i]=read();
    sort(a,a+n);
    for (long long i=n-1;i>=0;--i)
        sum[i]=sum[i+1]+a[i];
    long long ans=0;
    for (long long i=0;i<n;++i)
    {
        if (a[i]==a[i+1])
            continue;
        long long l=0,r=i-1;
        while (l<=r)
        {
            const long long mid=l+r>>1;
            if ((i-mid)*a[i]-(sum[mid]-sum[i])<=m)
                r=mid-1;
            else
                l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    write(ans);
    return 0;
}