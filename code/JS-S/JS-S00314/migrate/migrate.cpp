#include<bits/stdc++.h>
using namespace std;
long long a[2000001];
long long n, d, cnt, mins = 1e18;
void fdfs(int s, int t, long long step) {
    if(step >= mins) return ;
    if(s >= t) {
        mins = min(mins, step);
        return ;
    }
    for(int i = s + 1; i <= t; i++) {
        if(a[i] - a[s] <= d) fdfs(i, t, step + 1);
        else break;
    }
}
void dfs(int s, int t, long long step) {
    if(step > mins) return ;
    if(s >= t) {
        if(step == mins) cnt++;
        return ;
    }
    for(int i = s + 1; i <= t; i++) {
        if(a[i] - a[s] <= d) dfs(i, t, step + 1);
        else break;
    }
}
void solve() {
    int ans = 0;
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int u = 1; u <= n; u++) {
        for(int v = u + 1; v <= n; v++) {
            cnt = 0;
            mins = 1e18;
            fdfs(u, v, 0);
            dfs(u, v, 0);
            if(cnt == 2) ans++;
        }
    }
    cout << ans << "\n";
}
int main() {
    //Give me a blue-gou pls,I'll do every thing
    //By Luogu-bilibiliTV
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while(t--)
        solve();
    return 0;
}
