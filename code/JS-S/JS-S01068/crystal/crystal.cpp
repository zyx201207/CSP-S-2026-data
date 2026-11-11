#include <bits/stdc++.h>

using namespace std;

long long n,m;
long long a[500005];
long long sum[500005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector<long long> ch[n+1];
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<i;j++)
        {
            sum[i]+=a[i]-a[j];
        }
    }
    auto x=upper_bound(sum+1,sum+n+1,m);
    cout<<x-sum-1;
    return 0;
}
