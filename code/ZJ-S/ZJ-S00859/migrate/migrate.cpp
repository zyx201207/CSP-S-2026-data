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
inline void print(ll x)
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
inline void princh(cll x,const char ch)
{
    print(x);
    putchar(ch);
}
cint N=2e6;
int n;
ll d,a[N+1];
int pre[N+1],suf[N+1];
int cl[N+1],cr[N+1];
ll ans;
void solve()
{
    // printf("---\n");
    n=read();
    d=read();
    for(int i=1;i<=n;++i)a[i]=read();
    ans=0;
    pre[1]=1;
    for(int i=2;i<=n;++i)
    {
        pre[i]=pre[i-1];
        while(a[i]-a[pre[i]]>d)++pre[i];
    }
    suf[n]=n;
    for(int i=n-1;i>=1;--i)
    {
        suf[i]=suf[i+1];
        while(a[suf[i]]-a[i]>d)--suf[i];
    }
    // for(int i=1;i<=n;++i)
    // {
    //     printf("%d:(%d,%d)\n",i,pre[i],suf[i]);
    // }
    for(int i=1;i<=n;++i)cl[i]=cr[i]=0;
    for(int i=1;i<=n;++i)
    {
        if(suf[i]==i)continue;
        ++cl[suf[i]];
        if(pre[suf[i]]==i)cl[suf[i]]+=cl[i];
    }
    for(int i=n;i>=1;--i)
    {
        if(pre[i]==i)continue;
        ++cr[pre[i]];
        if(suf[pre[i]]==i)cr[pre[i]]+=cr[i];
    }
    for(int i=1;i<n;++i)
    {
        if(pre[i]==i||suf[i+1]==i+1)continue;
        if(pre[i+2]==pre[i+1]||suf[i-1]==suf[i])continue;
        // printf("%d - %d\n",i,i+1);
        int sl=0,sr=0;
        if(pre[i]==pre[i+1])sl=cl[pre[i]];
        sl+=pre[i+2]-pre[i+1];
        if(pre[i+2]==i+1)--sl;
        if(suf[i]==suf[i+1])sr=cr[suf[i]];
        sr+=suf[i]-suf[i-1];
        if(suf[i-1]==i)--sr;
        // printf("%d*%d\n",sl,sr);
        ans+=1ll*sl*sr;
    }
    princh(ans,'\n');
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read();
    int T=read();
    while(T--)solve();
    return 0;
}