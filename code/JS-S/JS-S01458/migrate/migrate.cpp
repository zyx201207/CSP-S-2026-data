#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, t;

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    if (t <= 6) {
        for (int n, d;t--;) {
            cin >> n >> d;
            vector<int> v(n + 1);
            for (int i = 1; i <= n; i++) {
                cin >> v[i];
            }
            int res = 0;
            for (int i = 1; i <= n; i++) {
                vector<int> dp(n + 1, n + 1), cnt(n + 1);
                dp[i] = 0; cnt[i] = 1;
                for (int j = i + 1; j <= n; j++) {
                    for (int k = j; k >= i && v[j] - v[k] <= d; k--) {
                        if (dp[k] + 1 < dp[j]) {
                            dp[j] = dp[k] + 1;
                            cnt[j] = cnt[k];
                        }
                        else if (dp[k] + 1 == dp[j]) {
                            cnt[j] = min(3ll, cnt[j] + cnt[k]);
                        }
                    }
                    if (cnt[j] == 2) {
                        //cout << i << ' ' << j << endl;
                        res++;
                    }
                }
            }
            cout << res << endl;
        }
    }
    else if (t == 11 || t == 12) {
        for (int n, d;t--;) {
            cin >> n >> d;
            vector<int> v(n + 1);
            for (int i = 1; i <= n; i++) {
                cin >> v[i];
            }
            int x = d / (v[2] - v[1]);
            if (x == 1) cout << "0\n";
            else cout << max(0ll, n - x * 2 + 1) << endl;
        }
    }
    else {
        for (int n, d;t--;) {
            cin >> n >> d;
            vector<int> v(n + 1);
            for (int i = 1; i <= n; i++) {
                cin >> v[i];
            }
            int res = 0;
            for (int i = 1; i <= n; i++) {
                vector<int> dp(n + 1, n + 1), cnt(n + 1);
                dp[i] = 0; cnt[i] = 1;
                deque<int> q;
                q.push_back(i);
                unordered_map<int, int> ump;
                ump[0] = 1;
                for (int j = i + 1; j <= n; j++) {
                    for (; q.size() && v[j] - v[q.front()] > d; ) {
                        ump[dp[q.front()]] -= cnt[q.front()];
                        q.pop_front();
                    }
                    int k = q.front();
                    dp[j] = dp[k] + 1;
                    cnt[j] = min(3ll, ump[dp[k]]);
                    for (;q.size() && dp[q.back()] > dp[j]; q.pop_back());
                    q.push_back(j);
                    ump[dp[j]] += cnt[j];
                    //cout << dp[j] << ' ';
                    if (cnt[j] == 2) res++;
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}
/*

10 3
0 3 6 7 8 9 10 11 14 17

*/
