#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define ll long long
#define cll const long long
#define ull unsigned long long
using namespace std;
inline ll read()
{
    ll x=0,zf=1;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')zf=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*zf;
}
inline void print(int x)
{
    if(x==0)
    {
        putchar('0');
        return;
    }
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    char buf[20];
    int h=0;
    while(x)
    {
        buf[h]=x%10+'0';
        ++h;
        x/=10;
    }
    while(h--)putchar(buf[h]);
}
inline void princh(cint x,const char ch)
{
    print(x);
    putchar(ch);
}
cint N=5e5;
int n,ans=1;
ll a[N+1],s[N+1],m;
inline bool check(cint l,cint r)
{
    return a[r]*(r-l+1)-(s[r]-s[l-1])<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    int p=1;
    for(int i=1;i<=n;++i)
    {
        while(!check(p,i))++p;
        ans=max(ans,i-p+1);
    }
    print(ans);
    return 0;
}