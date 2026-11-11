
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int c, T;
int n, d;
int x[N], dis[N], cnt[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> T;
    while (T--) {
        int ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int i = 1; i <= n; i++) {
            memset(dis, 0, sizeof(dis));
            memset(cnt, 0, sizeof(cnt));
            for (int k = i + 1; k <= n; k++) {
                if (x[k] - x[i] > d) break ;
                if (dis[k] != 0 && dis[k] != dis[i] + 1) continue ;
                dis[k] = dis[i] + 1;
                cnt[k] += 1;
            }
            for (int j = i + 1; j <= n; j++) {
                if (dis[j] == 0) break ;
                for (int k = j + 1; k <= n; k++) {
                    if (x[k] - x[j] > d) break ;
                    if (dis[k] != 0 && dis[k] != dis[j] + 1) continue ;
                    dis[k] = dis[j] + 1;
                    cnt[k] += 1;
                }
            }
            for (int j = 1; j <= n; j++) {
                if (cnt[j] == 2) ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}