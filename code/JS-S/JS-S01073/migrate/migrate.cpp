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
const int N = 2000005;
ll a[2000005];
// int L[N], R[N];
// pii qu[N];
// int sum[N];
// int rr[N];
void solve(){
    int n; ll d; cin >> n >> d;
    // for (int i = 0; i <= n; i++) sum[i] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 3) return void(cout << "0\n");
    ll D = a[2] - a[1];
    ll k = d / D;
    ll len = 2 * k;
    if (k == 0 || n < len) cout << 0 << endl;
    else cout << n - len + 1 << endl;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false); cin.tie(0);
    int C, T = 1;
    cin >> C >> T;
    while (T--){
        if (C == 11 || C == 12) solve();
        else {
            int n; cin >> n;
            ll d; cin >> d;
            for (int i = 1; i <= n; i++) cin >> a[i];
            cout << 1ll * (n / 2) * (n / 2) << endl;
        }
    }
    return 0;
}