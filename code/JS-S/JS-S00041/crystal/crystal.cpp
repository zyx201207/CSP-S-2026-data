#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, ans = 1;
int a[N], sum[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while (l <= r) {
            int mid = l + r >> 1;
            if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) {
                if (ans < i - mid + 1) {
                    ans = i - mid + 1;
                }
                r = mid - 1;
            }
            else l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}