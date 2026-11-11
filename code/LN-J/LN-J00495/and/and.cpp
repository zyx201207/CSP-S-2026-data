#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define inf 1e18
#define ls (2 * k)
#define rs (2 * k + 1)
using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool in[N];
int n, m, a[N];

inline void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n; i++)
        cin >> a[i], in[i] = true;
    int ans = 0;
    for(int k = 30;k >= 0; k--){
        int now = (1ll << k), cnt = 0;
        for(int i = 1;i <= n; i++){
            if(in[i] == false) continue;
            if((a[i] & now) > 0) cnt += 1;
        }
        if(cnt < m) continue;
        ans += now;
        for(int i = 1;i <= n; i++){
            if(in[i] == false) continue;
            if((a[i] & now) == 0) in[i] = false;
        }
    }
    cout << ans << "\n";
    return ;
}
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc = 1;
    while(tc--) solve();
    return 0;
}