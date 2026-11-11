#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
#define int long long

int n, m, a[N], ans;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int last = a[1], pre = 1, cost = 0;
    pair<int, int> qu[N];
    int front = 0, back = 1;
    for (pre = 1; pre <= n; pre++)
        if (a[pre] != a[pre + 1])
            break;
    qu[front] = {a[1], pre};
    ans = pre;
    for (int i = pre + 1; i <= n; i++) {
        int res = pre, cnt = 1;
        for (; i <= n; i++, cnt++)
            if (a[i] != a[i + 1])
                break;
        res += cnt;
        cost += pre * (a[i] - last);
        while (cost > m && front < back) {
            int cha = a[i] - qu[front].first;
            if (qu[front].second * cha <= cost - m) {
                cost -= qu[front].second * cha;
                res -= qu[front].second;
                front++;
            } else {
                int cnt = (cost - m + cha - 1) / cha;
                qu[front].second -= cnt;
                cost -= cnt * cha;
                res -= cnt;
                if (qu[front].second == 0)
                    front++;
                break;
            }
        }
        qu[back++] = {a[i], cnt};
        last = a[i];
        pre = res;
        ans = max(ans, res);
    }
    cout << ans << '\n';
    return 0;
}