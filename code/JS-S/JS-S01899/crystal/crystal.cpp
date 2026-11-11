#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
ll n, m, a[500005], sum[500005];
int main()
{
    IOS;
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = n; i >= 1; i --) sum[i] = sum[i + 1] + a[n] - a[i];
    int ans = 0;
    for(int i = n; i >= 1; i --)
    {
        int l = 0, r = i - 1, ans1 = 0;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(m >= (ll)((ll)sum[i - mid] - (ll)sum[i] - (ll)mid * (ll)(a[n] - a[i]))) ans1 = mid, l = mid + 1;
            else r = mid - 1;
        }
        ans = max(ans, ans1 + 1);
    }
    cout << ans;
    return 0;
}
