#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e5+10;
int a[N],need[N],s[N];
int n,m;
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-f;
        c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}
bool check(int len)
{
    for(int i=1;i<=n;i++) s[i]=0;
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        if(i<len) continue;
        if(a[i]*len-(s[i]-s[i-len])<=m) return true;
    }
    return false;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    int l=0,r=n,res=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    printf("%lld\n",res);
    // for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    // for(int i=1;i<=n;i++) need[i]=a[i]*i-s[i];
    // sort(need+1,need+n+1);
    // for(int i=1;i<=n;i++) cout<<"i:"<<i<<" a:"<<a[i]<<" need:"<<need[i]<<'\n';
    // cout<<ans<<'\n';
    return 0;
}