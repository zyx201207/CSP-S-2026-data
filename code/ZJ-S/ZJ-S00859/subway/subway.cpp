#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define ll long long
#define cll const long long
#define ull unsigned long long
using namespace std;
inline int read()
{
    int x=0,zf=1;
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
cint N=500,M=5e5;
cll inf=1e18;
#define pair pair<int,int>
#define x first
#define y second
int n,m,q;
int w[M+1];
vector<pair>to[M+1];
ll d[N+1][N+1];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read();
    n=read();
    m=read();
    read();
    q=read();
    for(int i=1;i<=m;++i)w[i]=read();
    for(int i=1;i<=n;++i)
    {
        int k=read();
        while(k--)
        {
            cint x=read(),val=read();
            to[x].push_back(pair(i,val));
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)d[i][j]=(i==j?0:inf);
    }
    for(int i=1;i<=m;++i)
    {
        for(pair p:to[i])
        {
            for(pair q:to[i])
            {
                d[p.x][q.x]=min(d[p.x][q.x],1ll*p.y+q.y);
            }
        }
    }
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    while(q--)
    {
        cint x=read(),y=read();
        ll ans=inf;
        for(pair p:to[x])
        {
            for(pair q:to[y])
            {
                ans=min(ans,p.y+q.y+d[p.x][q.x]);
            }
        }
        princh(ans+w[x]+w[y],'\n');
    }
    return 0;
}