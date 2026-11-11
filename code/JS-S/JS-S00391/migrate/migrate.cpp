#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+5;
int c,t,n,d;
int cnt;
int x[100];
int ans[100][100];
int read()
{
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
        {
            f=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        k=k*10+(c-'0');
        c=getchar();
    }
    return k*f;
}
void write(int x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x<10)
    {
        putchar(x+'0');
    }
    else
    {
        write(x/10);
        putchar(x%10+'0');
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();t=read();
    while(t--)
    {
        n=read();d=read();
        for(int i=1;i<=n;i++)
        {
            x[i]=read();
        }
        write(cnt);
        putchar('\n');
    }
    return 0;
}
