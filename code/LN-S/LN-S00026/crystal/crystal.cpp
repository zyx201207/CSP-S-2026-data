#include<bits/stdc++.h>
using namespace std;
long long read()
{
    long long ret=0;
    int sgn=0,ch=getchar();
    while(ch<'0'||ch>'9')sgn|=ch=='-',ch=getchar();
    while('0'<=ch&&ch<='9')ret=ret*10+ch-48,ch=getchar();
    return sgn? -ret:ret;
}
const int maxn=5*1e5+5;
long long n,m,a[maxn],sum[maxn];
bool check(int len)
{
    bool found=0;
    long long del=0;
    for(int i=1;i<=n-len+1&&(!found);i++)
    {
        del=0;
        del=(long long) (len-1)*a[i+len-1];
        del-=(sum[i+len-2]-sum[i-1]);
        if(del<=m)
        {
            found=1;
            //cout<<len<<' '<<i<<' '<<del<<endl;
        }
    }
    return found;
}
int main()
{
    freopen("crystal1.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int l=0,r=n,ans=0;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else r=mid;
    }
    if(ans==n-1)
    {
        if(check(n))ans=n;
    }
    //bool q=check(ans);
    cout<<ans;
    return 0;
}
