#include <bits/stdc++.h>
using namespace std;

#define FIO "crystal"

using ll = long long;
using pii = pair <int, int>;

const int MOD = 998244353;

int n;
ll m, a[500005], sum[500005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(FIO".in", "r", stdin);
    freopen(FIO".out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];

    int p = 0;
    int ans = 0;
    for (int i = 0; i < n; i++){
        while ((ll)(i - p + 1) * a[i] - (sum[i + 1] - sum[p]) > m) p++;
        ans = max(ans, i - p + 1);
    }
    cout << ans << "\n";

    return 0;
}
// chennie bless me