#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 500005;
int n, m;
ll last[maxn], a[maxn];
ll cnt[maxn], dp[maxn], add[maxn];
ll ans[maxn];
void dfs(int pos) {
    if (pos > n) return;
    if (dp[pos]) return;
    int nxt = last[a[pos]];
    if (nxt == pos) {
        add[pos] = pos + 1;
        dp[pos] = a[pos];
        dfs(pos + 1);
    }
    else {
        add[pos] = add[nxt] = nxt + 1;
        dp[pos] = dp[nxt] = a[pos];
        dfs(nxt + 1);
    }
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) dfs(i);
    // for (int i = 1; i <= n; i++) cout << dp[i] << " " << cnt[i] << '\n';
    // for (int i = 1; i <= n; i++) cout << add[i] << '\n';
    for (int i = 1; i <= n; i++) cnt[i] = 1;
    for (int i = 1; i <= n; i++) {
        cnt[add[i]] += cnt[i];
        ans[a[i]] += cnt[i];
        cnt[i] = 0;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << (i == m ? '\n' : ' ');
    return 0;
}