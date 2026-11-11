#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m,a[N],f[N],ans[M];
bool ok[M];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
        {
            f=-1;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(int x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read(); m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]==a[j])
            {
                f[j]=i;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            ok[a[j]]=1;
            if(f[j])
            {
                j=f[j];
            }
        }
        for(int j=1;j<=m;j++)
        {
            ans[j]+=ok[j];
            ok[j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
