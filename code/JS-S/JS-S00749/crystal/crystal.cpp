#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long p=0,need=0;
    for(long long i=1;i<n;i++)
    {
        need+=(i-p)*(a[i]-a[i-1]);
        for(;need>m;p++)
        {
            need-=(a[i]-a[p]);
        }
        ans=max(ans,i-p+1);
    }
    cout<<ans;
    return 0;
}
