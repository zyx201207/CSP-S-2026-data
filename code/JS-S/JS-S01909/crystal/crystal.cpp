#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 5;
ll n, m, a[N], ans = -1;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll sum = m, k = 1;
        while ((sum >= a[i] - a[i - k]) && (k < i))
        {
            sum -= a[i] - a[i - k];
            k++;
        }
        ans = max(ans, k);
    }
    cout << ans << '\n';
    return 0;
}