#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 5e5 + 10;
int n;
i64 m, a[N];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0; i64 cur = 0;
    for (int i = 1, l = 1; i <= n; i++) {
        cur += a[i];
        while (a[i] * (i - l + 1) - cur > m) {
            cur -= a[l];
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << endl;
    return 0;
}