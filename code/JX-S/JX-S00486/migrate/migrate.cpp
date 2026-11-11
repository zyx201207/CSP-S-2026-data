#include <bits/stdc++.h>
#define int long long
#define lc(x) ((x) << 1)
#define rc(x) (((x) << 1) ^ 1)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int MOD = 998244353;
int c, t, n, m, a[2000005], rgt[2000005], dis[2000005], vis[2000005], cnt[2000005];
void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s] = 1, dis[s] = 0, cnt[s] = 1;
    while (q.size()){
        int x = q.front();
        q.pop();
        for (int i = x + 1; i <= rgt[x]; i++){
            if (dis[i] == dis[x] + 1) cnt[i] += cnt[x];
            else if (dis[i] > dis[x] + 1) dis[i] = dis[x] + 1, cnt[i] = cnt[x];
            if (vis[i]) continue;
            vis[i] = 1;
            q.push(i);
        }
    }
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) rgt[i] = upper_bound(a + 1, a + n + 1, a[i] + m) - a - 1;
        if (c <= 6 && c >= 1){
            int ans = 0;
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++) vis[j] = 0, dis[j] = 1e18, cnt[j] = 0;
                bfs(i);
                for (int j = 1; j <= n; j++) if (cnt[j] == 2) ans++;
            }
            cout << ans << "\n";
        } else if (c >= 13 && c <= 14){
            int cnt = 0, pos = -1;
            for (int i = 1; i <= n; i++){
                if (rgt[1] >= i && rgt[i] == n){
                    cnt++;
                    if (pos == -1) pos = i;
                }
            }
            if (cnt >= 3){ cout << 0 << "\n"; continue; }
            int ans = 0;
            for (int i = 1; i <= n; i++){
                if (rgt[1] >= i && rgt[i] == n) break;
                if (cnt == 1 && (rgt[i] == pos + 1 || rgt[i] == pos)) ans += rgt[rgt[i] - 1] - rgt[i];
                else if (cnt == 2 && rgt[i] == pos + 1) ans += n - rgt[i];
            }
            cout << ans << "\n";
        } else if (c >= 11 && c <= 12 || c == 0){
            if (rgt[1] == 1 || rgt[1] == 2 || rgt[1] >= 4){ cout << 0 << "\n"; continue; }
            else {
                int ans = 0;
                for (int i = 1; i <= n; i++){
                    ans += (n - i - 1) / 2;
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}

