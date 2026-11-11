#include <bits/stdc++.h>
using namespace std;
#define _N 5005
#define N 2000005
#define int long long
int subtask, T, n, d, a[N], pos[N], dis[_N][_N], cnt[_N][_N], ans;
queue<int> que;
void bfs(int s) {
    que.push(s);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(int v = u + 1;v <= pos[u];v++) {
            if(!cnt[s][v]) que.push(v), dis[s][v] = dis[s][u] + 1;
            if(dis[s][u] < dis[s][v]) cnt[s][v] += cnt[s][u];
        }
    }
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> subtask >> T;
    if(11 <= subtask && subtask <= 12) {
        while(T--) {
            cin >> n >> d;
            for(int i = 1;i <= n;i++) cin >> a[i];
            if(a[1] == a[2]) { cout << 0 << endl; continue; }
            d /= (a[2] - a[1]);
            if(d <= 1) cout << 0 << endl;
            else cout << max(n - 2 * d + 1, 0ll) << endl;
        }
        return 0;
    }
    while(T--) {
        cin >> n >> d; ans = 0;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) cnt[i][j] = 0, dis[i][j] = 1e18;
            cnt[i][i] = 1; pos[i] = n;
            for(int j = i + 1;j <= n;j++)
                if(a[j] - a[i] > d) { pos[i] = j - 1; break; }
        }
        for(int i = 1;i <= n;i++) bfs(i);
        for(int i = 1;i <= n;i++)
            for(int j = i + 1;j <= n;j++) ans += (cnt[i][j] == 2);
        cout << ans << endl;
    }
    return 0;
}
