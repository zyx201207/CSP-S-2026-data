#include<bits/stdc++.h>
#define int long long
#define M 500005
using namespace std;
int n, m, a[M];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int cc = 0, sum = 0, ans = 0;
    for(int i = 1, j = 1; i <= n; i++)
    {
        cc++;
        sum -= a[i];
        while(a[i] * cc + sum > m) cc--, sum += a[j], j++;
        ans = max(ans, cc);
    }
    cout << ans << '\n';
    return 0;
}
