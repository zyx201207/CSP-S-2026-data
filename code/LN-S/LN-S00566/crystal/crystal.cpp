#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,a[N],m;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int maxn=1;
    for (int i=2;i<=n;i++)
    {
        int tt=i-1,t=m,ans=0;
        while (t>=0 && tt>=1)
        {
            if (a[i]-a[tt]<=t)
            {
                ans++;
                t-=(a[i]-a[tt]);
            }
            tt--;
        }
        maxn=max(maxn,ans);
    }
    cout<<maxn+1;
    return 0;
}
