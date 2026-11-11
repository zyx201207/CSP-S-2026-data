#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
const int N = 2e5+10;
ll a[N];
ll ans = 1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    if (m == 1)
    {
        for (int i = 1;i <= n;i++)
            ans = max(a[i],ans);
    }
    if (m == 2)
    {
        for (int i = 1;i <= n;i++)
            for (int j = i+1;j <= n;j++)
                ans = max(ans,a[i]&a[j]);
    }
    if (m == n)
    {
        for (int i = 1;i <= n;i++)
            ans &= a[i];
    }
    if (m == n-1)
    {
        ans = 0;
        for (int i = 1;i <= n;i++)
        {
            ll sum = 1;
            for (int j = 1;j < i;j++)
                sum &= a[j];
            for (int j = i+1;j <= n;j++)
                sum &= a[j];
            ans = max(ans,sum);
        }
    }
    else
    {
        ans = 0;
    }
    cout << ans;
    return 0;
}
