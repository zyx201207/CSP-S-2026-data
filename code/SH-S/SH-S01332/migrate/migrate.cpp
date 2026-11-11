#include <iostream>
#include <cstring>
#include <queue>
#include <cassert>
using namespace std;

using LL = long long;

const LL N = 2e6 + 10;
LL x[N], dp[N], cnt[N];
LL n, d;

LL solve_case_1_6() {
    LL pair_cnt = 0;
    for (LL l = 1; l <= n; l++) {
        memset(dp, 0x3f, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        dp[l] = 0; cnt[l] = 1;
        for (LL i = l + 1; i <= n; i++) {
            for (LL j = i - 1; j >= l - 1 && x[i] - x[j] <= d; j--) {
                if (dp[j] + 1 < dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
            if (cnt[i] == 2) {
                pair_cnt++;
            }
        }
    }
    return pair_cnt;
}

LL solve_case_7_10() {
    LL pair_cnt = 0;
    for (LL l = 1; l <= n; l++) {
        memset(dp, 0x3f, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        dp[l] = 0; cnt[l] = 1;
        deque<LL> q(1, l);
        for (LL i = l + 1; i <= n; i++) {
            while (!q.empty() && x[i] - x[q.front()] > d) {
                q.pop_front();
            }
            dp[i] = dp[q.front()] + 1;
            for (LL j : q) {
                if (dp[j] + 1 > dp[i]) {
                    break;
                }
                cnt[i] += cnt[j];
            }
            while (!q.empty() && dp[i] < dp[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            if (cnt[i] == 2) {
                pair_cnt++;
            }
        }
    }
    return pair_cnt;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL c, t;
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (LL i = 1; i <= n; i++) {
            cin >> x[i];
        }
        if (1 <= c && c <= 6) {
            cout << solve_case_1_6() << endl;
        } else {
            cout << solve_case_7_10() << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
