#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
void cmax(int &x,int y)
{
    x=max(x,y);
}
void cmin(int &x,int y)
{
    x=min(x,y);
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar('0'+x%10);
}
const int N=5e5+5;
int n,m,a[N],ans,s[N];
int calc(int l,int r)
{
    return a[r]*(r-l+1)-(s[r]-s[l-1]);
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int i=1,j=1;i<=n;i++)
    {
        if(j<i)
            j=i;
        while(j<n&&calc(i,j+1)<=m)
            j++;
    //    if(j-i>3844)
    //        cout<<i<<' '<<j<<' '<<calc(i,j)<<' '<<m<<endl;
     //   cout<<i<<' '<<j<<endl;
        cmax(ans,j-i+1);
    }
    write(ans);
    return 0;
}
