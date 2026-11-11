#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
ll n, a[N], ans;
char c[N];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i] >> c[i];
    }
    int headp = 1, tailp = n;
    while (headp < tailp)
    {
        if (c[headp] != c[tailp]) ans += min(a[headp], a[tailp]);
        ll mn = min(a[headp], a[tailp]);
        a[headp] -= mn;
        a[tailp] -= mn;
        if (a[headp] == 0) headp ++;
        if (a[tailp] == 0) tailp --;
    }
    cout << ans << endl;
    return 0;
}