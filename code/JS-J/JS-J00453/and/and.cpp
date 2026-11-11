#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
bool skip[200005];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (skip[j]) continue;
            cnt += ((a[j] >> i) & 1);
        }
        if (cnt >= m)
        {
            ans |= (1 << i);
            for (int j = 1; j <= n; j++)
            {
                if (skip[j]) continue;
                if (((a[j] >> i) & 1) == 0) skip[j] = 1;
            }
        }
    }
    cout << ans;
    return 0;
}
