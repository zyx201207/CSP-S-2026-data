#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],sum[500005],n,m;
int check(int x)
{
    for (int i = 1;i <= n;i ++)
    {
        if (i+x-1>n) break;
        if (a[i+x-1]*x-(sum[i+x-1]-sum[i-1])<=m) return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i ++)
    {
        cin >> a[i];

    }
    sort(a+1,a+n+1);
    for (int i = 1;i <= n;i ++)sum[i] = sum[i-1]+a[i];
    int l = 1,r = n+1,res = 0;
    while(l < r)
    {
        int mid = (l+r)/2;
        if (check(mid))
        {
            l = mid+1;
            res = mid;
        }
        else
            r = mid;
    }
    cout << res << '\n';
    return 0;
}
