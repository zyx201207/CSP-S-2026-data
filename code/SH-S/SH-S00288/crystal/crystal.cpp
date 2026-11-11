#include <bits/stdc++.h>
using namespace std;
#define int long long

int sum[500010];
int a[500010];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    scanf("%lld%lld",&n,&m);
    for (int i = 1;i <= n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1;i <= n;i++)
    {
        int l = 1;
        int r = i;
        while (l < r)
        {
            int mid = (l + r - 1) >> 1;
            if ((i - mid + 1) * a[i] - sum[i] + sum[mid - 1] <= m)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        ans = max(ans,i - r + 1);
    }
    cout << ans << endl;
    return 0;
}
