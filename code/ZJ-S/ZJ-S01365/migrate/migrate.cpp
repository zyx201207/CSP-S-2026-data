#include<bits/stdc++.h>
#define ll long long
#define il inline
#define gc getchar
#define pc putchar
using namespace std;
int read_int()
{
    int x=0,y=1;
    char ch=gc();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')y=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=gc();
    }
    return x*y;
}
ll read_ll()
{
    ll x=0,y=1;
    char ch=gc();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')y=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=gc();
    }
    return x*y;
}
void write_int(int x)
{
    if(x<0)
    {
        x=-x;
        pc('-');
    }
    if(!x)
    {
        pc('0');
        return;
    }
    char st[20];
    int tot=0;
    while(x)
    {
        st[++tot]=x%10+48;
        x/=10;
    }
    while(tot)pc(st[tot--]);
}
void write_ll(ll x)
{
    if(x<0)
    {
        x=-x;
        pc('-');
    }
    if(!x)
    {
        pc('0');
        return;
    }
    char st[20];
    int tot=0;
    while(x)
    {
        st[++tot]=x%10+48;
        x/=10;
    }
    while(tot)pc(st[tot--]);
}
const int N=2e6+5,N1=5005;
int c,T;
int n;
ll d,a[N];
int f[N1][N1],ans[N1][N1];
void solve1()
{
    memset(f,0x3f3f3f3f,sizeof(f));
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){ll diff=a[i]-a[j];if(diff<0)diff=-diff;if(diff<=d){f[i][j]=f[j][i]=1;ans[i][j]++;ans[j][i]++;}}
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(f[i][j]==f[i][k]+f[k][j])ans[i][j]++;
                if(f[i][j]>f[i][k]+f[k][j])
                {
                    f[i][j]=f[i][k]+f[k][j];
                    ans[i][j]=1;
                }
            }
        }
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(ans[i][j]==2)res++;
        }
    }
    write_ll(res);
    pc('\n');
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read_int();
    T=read_int();
    while(T--)
    {
        n=read_int();
        d=read_ll();
        for(int i=1;i<=n;i++)a[i]=read_ll();
        if(n<=5000)solve1();
    }
    return 0;
}