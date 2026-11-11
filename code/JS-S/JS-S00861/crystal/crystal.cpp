#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int const N=5e5+5;
long long a[N],sum[N];
long long m;
long long n;
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
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        long long k=a[i];
        if(i*k-sum[i]<=m)
        {
            ans=max(i,ans);
        }

    }
    cout<<ans;
    return 0;
}
