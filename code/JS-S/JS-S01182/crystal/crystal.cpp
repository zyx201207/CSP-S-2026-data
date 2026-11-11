#include<bits/stdc++.h>
using namespace std;
constexpr int N= 5e5+5;
long long a[N];
long long sum[N];
int n;
long long m;
int check(int x)
{

    for(int i=x;i<=n;i++)
    {
        long long al=sum[i]-sum[i-x];
        long long sh=a[i]*x;
        if(sh-al<=m)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    long long l,r,mid,ans;
    l=1,r=n;
    while(l<=r)
    {
        mid=(r-l)/2+l;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
