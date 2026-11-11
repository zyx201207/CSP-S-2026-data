#include<bits/stdc++.h>

#define int long long

using namespace std;

//typedef long long ll;

const int MAXN = 5e5 + 5;

int a[MAXN], b[MAXN];
int sum[MAXN], tot[MAXN];

signed main()
{
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie (0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        tot[i] = m - i * a[i] + sum[i - 1];
        b[i] = a[i] - a[i - 1];
    }
    int ans = 1;
    for (int i = 2, j = 1; i <= n; i++)
    {
        while (sum[j - 1] - j * a[i] > tot[i])
            j++;
        ans = max (ans, i - j + 1);
    }
    cout << ans;
    return 0;
}
