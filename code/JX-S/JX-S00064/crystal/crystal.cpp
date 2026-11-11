#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-x;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
ll n,m,a[500005];
bool pd_xd()
{
    for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) return 0;
    return 1;
}
bool pd_dc(int gc)
{
    for(int i=2;i<=n;i++) if(a[i]-a[i-1]!=gc) return 0;
    return 1;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
    }
    sort(a,a+n);
    int gc=a[n]-a[n-1];
    if(pd_xd())
    {
        cout<<n;
        return 0;
    }
    else if(pd_dc(gc))
    {
        int i=0;
        ll j=gc,k=gc;
        while(i<n-1&&j<=m)
        {
            m-=gc;
            i++;
            j+=k;
            k+=gc;
        }
        cout<<i+1;
        return 0;
    }

    return 0;
}
