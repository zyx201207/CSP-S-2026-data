#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],sum[500005];
int find(int x)
{
    int l=1,r=x;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(a[x]*(x-mid+1)-(sum[x]-sum[mid-1])>m)
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    return l;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,i-find(i)+1);
    }
    cout << ans;
    return 0;
}
