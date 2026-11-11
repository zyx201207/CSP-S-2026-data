#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],x[500005];
int ans=-1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        x[i]=x[i-1]+a[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            if(a[j]*(j-i+1)-x[j]-x[i-1]<=m) ans=max(ans,j-i+1);
        }
    }
    cout << ans;
    return 0;
}
