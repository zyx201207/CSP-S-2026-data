#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define inf 1e18
#define ls (2 * k)
#define rs (2 * k + 1)
using namespace std;

const int mod = 1e9 + 7;
const int N = 5e5 + 5, M = 3e5 + 5;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int suf[M], ans[M];
int n, m, a[N], f[N];

inline void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n; i++)
        cin >> a[i], suf[a[i]] = i;
    for(int i = 1;i <= n; i++){
        f[i] = f[i] + 1;
        int to = suf[a[i]] + 1;
        if(to <= n) f[to] += f[i];
    }
    for(int i = 1;i <= n; i++)
        ans[a[i]] += f[i];
    for(int i = 1;i <= m; i++)
        cout << ans[i] << " \n"[i == m];
    return ;
}
signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc = 1;
    while(tc--) solve();
    return 0;
}