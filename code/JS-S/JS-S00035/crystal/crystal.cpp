#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;
ll a[N], s[N];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n, m, ans = 1, j = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = a[i] + a[i - 1];
    for (int i = 2; i <= n; i++)
    {
        ll cost = (i - j) * a[i] - s[i - 1] + s[j - 1];
        if (cost <= m) ans = max(ans, i - j + 1);
        else
        {
            j++;
            if (j > i) i = j + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
