#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, x[2000006], ans = 0, ccnt = LLONG_MAX, answer;
void dfs(int s, int e, int cnt, int idx) {
    if (cnt > ccnt || x[idx] > x[e]) return ;
    if (x[idx] == x[e]) {
        if (ccnt > cnt) {
            ccnt = cnt;
            ans = 1;
        } else if (cnt == ccnt) ans++;
        return ;
    }
    for (int i = idx + 1; i <= e; i++) {
        if (x[i] - x[idx] > d) break;
        dfs(s, e, cnt + 1, i);
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        answer = 0, ans = 0, ccnt = LLONG_MAX;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans = 0, ccnt = LLONG_MAX;
                dfs(i, j, 0, i);
                if (ans == 2) answer++;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}
