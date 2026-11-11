#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],ans;
bool ok;
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
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read(); m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
    }
    for(int i=1;i<(1<<n);i++)
    {
        int cnt=0,tep=0;
        ok=1;
        for(int j=0;(1<<j)<=i;j++)
        {
            if(i&(1<<j))
            {
                cnt++;
                if(!tep&&ok)
                {
                    tep=a[j+1];
                    ok=0;
                }
                tep=tep&a[j+1];
            }
        }
        if(cnt>=m) ans=max(ans,tep);
    }
    write(ans);
    return 0;
}
