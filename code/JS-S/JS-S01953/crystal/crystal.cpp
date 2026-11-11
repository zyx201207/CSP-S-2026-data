#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500010];
long long sum[500010];

bool check(int x)
{
    for(int i=1;i<=n-x+1;i++)
    {
        if(x*a[i+x-1]-(sum[i+x-1]-sum[i-1])<=m)
        {
            return true;
        }
    }
    return false;
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
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n;
    int mid;
    //cout<<check(3)<<" "<<check(4)<<endl;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<l-1;
    return 0;
}
