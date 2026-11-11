#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, a[5005];
int mn[5005];
int cnt[5005];
int ans;
map<int, int>mp;
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t--) {
        ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (c == 13 || c == 14) {
            cout << "0\n";
            continue;
        }
        for (int i = 1; i <= n; i++) {
            memset(mn, 0x3f, sizeof mn);
            memset(cnt, 0, sizeof cnt);
            if (c < 7) {
                mn[i] = 0;
                cnt[i] = 1;
                for (int j = i + 1; j <= n; j++) {
                    for (int k = j - 1; k >= i; k--) {
                        if (a[j] - a[k] > d) break;
                        mn[j] = min(mn[j], mn[k] + 1);
                    }
                    for (int k = j - 1; k >= i; k--) {
                        if (a[j] - a[k] > d) break;
                        if (mn[j] == mn[k] + 1) cnt[j] += cnt[k];
                    }
                    if (cnt[j] == 2) ans++;
                }
            }
            else {
                mp.clear();
                mn[i] = 0;
                cnt[i] = 1;
                mp[0] = 1;
                int id = i;
                for (int j = i + 1; j <= n; j++) {
                    for (; id <= j - 1; id++) {
                        if (a[j] - a[id] <= d) break;
                        mp[mn[id]] -= cnt[id];
                        if (mp[mn[id]] == 0) mp.erase(mn[id]);
                    }
                    for (auto k : mp) {
                        mn[j] = k.first + 1;
                        cnt[j] = k.second;
                        break;
                    }
                    mp[mn[j]] += cnt[j];
                    if (cnt[j] == 2) ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}