#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 5e5 + 5;
typedef long long ll;

int n;
ll m, a[N], s[N];
void Main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = 1, res = 1;
    ll tot = 0;
    while (r <= n)
    {
        while (tot > m)
        {
            tot -= a[r] - a[l];
            ++l;
        }
        res = max(res, r - l + 1);
        if (r < n)
        {
            tot += (a[r + 1] - a[r]) * (r - l + 1);
        }
        ++r;
    }
    cout << res << endl;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TaskCnt = 1;
    // cin >> TaskCnt;
    while (TaskCnt--)
        Main();
    return 0;
}