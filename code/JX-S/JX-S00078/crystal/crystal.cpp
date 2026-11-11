#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,a[N],m;
long long read()
{
    long long sum=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
            sum=(sum<<3)+(sum<<1)+(c^48),c=getchar();
    return sum*f;
}
bool check(int x)
{
    for(int i=x;i<=n;i++)
    {
        long long sum=x*(a[i]-a[i-1]);
        sum-=(a[i]-a[i-x]);
        if(sum<=m)
            return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        a[i]+=a[i-1];
    int l=1,r=n,ans;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
