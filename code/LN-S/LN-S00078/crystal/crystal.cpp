#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,cf[500005],s[500005],ss[500005];
bool check(long long x)
{
    long long sum=1e18;
    for(int i=1;i<=n-x+1;i++)
    {
        sum=min(sum,ss[i+x-2]-ss[i-1]-(x-1)*s[i+x-1]);
        if(sum<=m)
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
    for(int i=1;i<n;i++)
    {
        cf[i]=a[i+1]-a[i];
    }
    for(int i=n-1;i>=1;i--)
    {
        s[i]=s[i+1]+cf[i];
    }
    for(int i=1;i<n;i++)
    {
        ss[i]=ss[i-1]+s[i];
    }
    long long l=1,r=n;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}
