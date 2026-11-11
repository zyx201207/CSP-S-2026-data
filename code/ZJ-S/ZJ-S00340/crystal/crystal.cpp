#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+8;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
    while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,m;
int a[N],b[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);

    int l=1,r=1,ans=1,res=0;
    while(r<=n)
    {
        r++;
        res+=(a[r]-a[r-1])*(r-l);
        while(res>m) res-=a[r]-a[l],l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}
