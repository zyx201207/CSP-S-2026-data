#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 5e5 + 5;
int n;
ll m;
ll a[N], sum[N];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int l = 1, r = i;
        while (l < r){
            int mid = (l + r) >> 1;
            ll val = a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]);
            // cout << mid << " " << i << " " << val << endl;
            if (val <= m) r = mid;
            else l = mid + 1;
        }
        // cout << l << endl;
        ans = max(ans, i - l + 1);
    }
    cout << ans << endl;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) solve();
    return 0;
}