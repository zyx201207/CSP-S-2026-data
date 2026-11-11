#include "bits/stdc++.h"
#define F(i,x,y) for (int i = (x); i <= (y); ++ i)
#define D(i,x,y) for (int i = (x); i >= (y); -- i)
#define ll long long
#define ull unsigned long long
#define OPEN freopen ("crystal.in", "r", stdin); freopen ("crystal.out", "w", stdout);
#define IOS ios :: sync_with_stdio (false); cin.tie (0); cout.tie (0);
using namespace std;
constexpr int N = 5e5 + 5;

int n; ll m;
ll a[N], pre[N], ans;
int main () {
    OPEN
    IOS
    cin >> n >> m;

    F (i, 1, n) cin >> a[i];
    sort (a + 1, a + n + 1);
    F (i, 1, n) pre[i] = pre[i - 1] + a[i];
    F (i, 1, n) {
        int L = 1, R = i, pos = i + 1;
        while (L <= R) {
            int mid = (L + R) >> 1;
            // [mid, i]
            if ((i - mid + 1) * a[i] - (pre[i] - pre[mid - 1]) <= m) pos = mid, R = mid - 1;
            else L = mid + 1;
        }
        // if (1LL * i - pos + 1 >= ans) cerr << pos << ' ' << i << '\n';
        ans = max (ans, 1LL * i - pos + 1);
    }

    // cerr << a[4238] << ' ' << a[3] << ' ' << pre[4238] - pre[2] << '\n';

    cout << ans << '\n';
    return 0;
}