#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define inf 1e18
#define ls (2 * k)
#define rs (2 * k + 1)
using namespace std;
// crystal
const int mod = 1e9 + 7;
const int N = 5e5 + 5, M = 3e5 + 5;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
mt19937_64 rng(time(0));

int n, m, a[N], S[N];

inline bool check(int w, int p){
    int v = (p - w + 1) * a[p] - (S[p] - S[w - 1]);
    return v <= m;
}

inline void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n; i++) S[i] = S[i - 1] + a[i];
    int ans = 0;
    for(int i = 1;i <= n; i++){
        int l = 1, r = i;
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid, i)) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << "\n";
    return ;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc = 1;
    while(tc--) solve();
    
    return 0;
}