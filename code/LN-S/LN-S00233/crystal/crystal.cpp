#include <bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=0,r=1;
    long long maxn=0;
    while(r<=n)
    {
        sum[r]=sum[r-1]+a[r];
        long long mis=a[r]*(r-l)-sum[r]+sum[l];
        if(mis>m)
        {
            l++;
        }
        else
        {
            maxn=max(maxn,r-l);
            r++;
        }
    }
    cout<<maxn;
    return 0;
}
