#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e6 + 5;
const int P = 1e9 + 7;
int c, t, n, d, dp[5005][5005], a[N];
void solve(){
    cin >> n >> d;
    bool f = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int flag = a[2] - a[1];
    for(int i = 3; i <= n; i++) if(a[i] - a[i - 1] != flag) f = 1;
    if(!f){
        cout << n << " " << flag << " " << d << " ";
        if(d < 2 * flag) cout << 0;
        else cout << max(n - d / flag - 1, 0LL);
        cout << endl;
        return;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) solve();
    return 0;
}
