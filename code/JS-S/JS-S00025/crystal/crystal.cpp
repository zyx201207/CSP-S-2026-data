#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = (s); i <= (e); i++)
#define dep(i, s, e) for (int i = (s); i >= (e); i--)
#define sz(x) (int)x.size()
#define ppc(x) __builtlin_popcnt(x)
#define pub push_back
using namespace std;

const int N = 5e5 + 5;
#define int long long
#define ll long long
#define i28 __int128

int a[N], s[N];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 1, n)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    rep(i, 1, n)
        s[i] = s[i - 1] + a[i];
    
    int ans = 0;
    rep(i, 1, n)
    {
        int l = 0, r = i;
        while (l + 1 < r)
        {
            int mid = l + r >> 1;
            if (s[i] - s[mid - 1] + m >= (i - mid + 1) * a[i]) r = mid;
            else l = mid;
        }
        ans = max(ans, i - r + 1);
    }
    cout << ans << "\n";
    return 0;
}