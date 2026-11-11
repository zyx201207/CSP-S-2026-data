#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 5e5 + 5;
int n, ans; ll m, a[MAXN], b[MAXN];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++) b[i] = b[i - 1] + a[i];
    for (int r = 1; r <= n; r ++) {
        int pl = 1, pr = r;
        while (pl != pr) {
            int mid = (pl + pr) >> 1;
            ll fin = (r - mid + 1) * a[r];
            ll ori = b[r] - b[mid - 1];
            if (fin - ori <= m) pr = mid;
            else pl = mid + 1;
        } ans = max(ans, r - pl + 1);
    } cout << ans; return 0;
}
