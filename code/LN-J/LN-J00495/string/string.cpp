#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define inf 1e18
#define ls (2 * k)
#define rs (2 * k + 1)
using namespace std;

const int mod = 1e9 + 7;
const int N = 2e5 + 5, M = 4e5 + 5;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

char ch;
int n, tot, a[N], p[N];
int pre[N], suf[N], all[M], id[M];

inline void solve(){
    cin >> n;
    for(int i = 1;i <= n; i++){
        cin >> a[i] >> ch;
        p[i] = (ch - 'a' + 1);
    }
    for(int i = 1;i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    for(int i = n;i >= 1; i--)
        suf[i] = suf[i + 1] + a[i];
    for(int i = 1;i <= n; i++)
        all[i] = pre[i], all[n + i] = suf[i];
    sort(all + 1, all + 2 * n + 1);
    tot = unique(all + 1, all + 2 * n + 1) - (all + 1);
    for(int i = 1;i <= tot; i++){
        int d = lower_bound(pre + 1, pre + n + 1, all[i]) - pre;
        id[i] = p[d];
    }
    int ans = 0;
    for(int i = 1;i <= tot; i++){
        int to = tot - i + 1;
        if(id[i] != id[to]) ans += (all[i] - all[i - 1]);
    }
    cout << ans / 2 << "\n";
    return ;
}
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc = 1;
    while(tc--) solve();
    return 0;
}