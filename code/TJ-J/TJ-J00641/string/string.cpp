#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MAXN = 2e5 + 100;

LL n, a[MAXN], ans;
char c[MAXN];
deque<pair<LL, char>> dq;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        if (i > 1 && c[i] == c[i - 1]) {
            a[i - 1] += a[i];
            i--;
            n--;
        }
    }
    for (int i = 1; i <= n; i++) {
        dq.push_back({a[i], c[i]});
    }
    while (dq.size() > 1) {
        auto [a1, c1] = dq.front();
        dq.pop_front();
        auto [a2, c2] = dq.back();
        dq.pop_back();
        if (c1 == c2) {
            if (a1 > a2) {
                dq.push_front({a1 - a2, c1});
            } else if (a1 < a2) {
                dq.push_back({a2 - a1, c2});
            }
        } else {
            if (a1 > a2) {
                ans += a2;
                dq.push_front({a1 - a2, c1});
            } else if (a1 < a2) {
                ans += a1;
                dq.push_back({a2 - a1, c2});
            } else {
                ans += a1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
