#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 10;

int n, m, a[maxn], b[maxn], ans;
bool okA = true, okB = true;
vector<int> ve;

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n <= 5000) {
        for (int i = 1; i <= n; i++) {
            int k = a[i], cnt = 1, sum = 0;
            for (int j = 1; j <= n; j++) {
                if (k >= a[j] && j != i) ve.push_back(k - a[j]);
            }
            sort(ve.begin(), ve.end());
            for (int i = 0; i < (int)ve.size(); i++) {
                sum += ve[i]; cnt++;
                if (sum > m){
                    ans = max(ans, --cnt);
                    break;
                }
                else if (sum == m) {
                    ans = max(ans, cnt);
                    break;
                }
            }
            ve.clear();
        }
        cout << ans << endl;
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (a[i] != i) okA = false;
            b[i] = a[i + 1] - a[i];
        }
        for (int i = 2; i < n; i++) {
            if (b[i] != b[i - 1]) okB = false;
        }
        if (okB) {
            int cur = 0, cnt = 0;
            while (true) {
                if (m - cur > 0) m -= cur, cnt++;
                else if (m - cur == 0) m -= cur, cnt++;
                else if (m - cur < 0) m -= cur;
                cur = cur + b[1];
                if (m <= 0) {
                    cout << cnt << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
