#include<bits/stdc++.h>
using namespace std;
long long m,n,ans;
long long a[500001];
inline long long read()
{
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
    return x*f;
}
int main()
{
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(long long i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    long long r=1,l=1;
    long long s=0;
    while(s<=m)r++,s+=(a[r]-a[r-1])*(r-1);
    s-=(a[r]-a[r-1])*(r-1);
    r--;
    ans=r;
    while(r<=n)
    {
        r++;
        s+=(a[r]-a[r-1])*(r-l);
        while(s>m)s-=(a[r]-a[l]),l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}

