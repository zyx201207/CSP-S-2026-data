#include <bits/stdc++.h>//t1:crystal
#define ll long long
using namespace std;

int n,ans;
ll m,a[500007],sum[500007];

ll solve(int pos,int i)
{
    ll diff = (ll)(i - pos + 1) * a[i] - (sum[i] - sum[pos - 1]);
    return diff;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for (int i = 1;i <= n;i++)sum[i] = sum[i - 1] + a[i];
    for (int i = 1;i <= n;i++)
    {
        int l = 1,r = i;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            ll val = solve(mid,i);
            if (val > m)
            {
                l = mid + 1;
            }
            else if (val == m)
            {
                l = r = mid;
            }
            else
            {
                r = mid;
            }
        }
        ans = max(ans,i - l + 1);
    }
    cout << ans << endl;
    return 0;
}
