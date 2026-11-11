#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int a[N];
char c[N];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
    int i = 1, cnti = 0, j = n, cntj = 0, ans = 0;
    while (i < j)
    {
        int x = min(a[i], a[j]);
        cnti += x, cntj += x;
        ans += x * (c[i] != c[j]);
        a[i] -= x, a[j] -= x;
        if (a[i] == 0)
            i++, cnti = 0;
        if (a[j] == 0)
            j--, cntj = 0;
    }
    cout << ans;
    return 0;
}