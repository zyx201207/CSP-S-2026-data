#include <bits/stdc++.h>
using namespace std;
int n, ans, p;
long long m, a[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        p = 0;
        for (int j = i; j >= 1;j--)
        {
            if (!m)
                break;
            if (m < a[i] - a[j])
                break;
            m -= (a[i] - a[j]);
            p++;
        }
        ans = max(ans, p);
    }
    ans++;
    cout << ans;
    return 0;
}
