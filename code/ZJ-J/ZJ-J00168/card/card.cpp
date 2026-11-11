#include <bits/stdc++.h>
using namespace std;
//#define int long long
constexpr int maxn=5e5+10;
constexpr int maxm=3e5+10;
int n,m;
int a[maxn];
int ans[maxm];
int lst[maxm];
int f=1;
inline int read()
{
    int g=1,t=0;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')
            g=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        t=(t<<1)+(t<<3)+ch-'0';
        ch=getchar();
    }
    return g*t;
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        lst[a[i]]=i;
        if(i>1 && a[i]<a[i-1] && f)
            f=0;
    }
    if(f)
    {
        for(int i=1;i<=m;++i)
        {
            printf("%d ",lst[i]);
        }
        return 0;
    }
    int pos;
    for(int i=1;i<=n;++i)
    {
        int col=a[i];
        ++ans[col];
        pos=i;
        while(pos<n)
        {
            pos=lst[col];
            col=a[pos+1];
            ++ans[col];
        }
    }
    for(int i=1;i<=m;++i)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
