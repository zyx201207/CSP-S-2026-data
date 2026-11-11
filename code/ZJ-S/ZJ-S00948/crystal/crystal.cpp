#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[500005],sum[500005];
ll n, m, ans = -1e9;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1;i--)
    {
        ll res = 0, cnt = 0;
        for (int j = i; j >= 1;j--)
        {
            if(res<=m-(a[i]-a[j]))
            {
                res += a[i] - a[j];
                cnt++;
            }
        }
        // cout << "case: " << i << ' ' << cnt << '\n';
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}