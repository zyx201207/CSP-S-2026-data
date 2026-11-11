#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], cnt[N], lst[N];
unordered_map<int, int> pos;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int k = 1; k <= n; ++k) {
        pos.clear();
        int len = 1;
        lst[1] = a[k], pos[a[k]] = 1;
        for (int i = k + 1; i <= n; ++i) {
            if (pos.count(a[i]) && pos[a[i]] <= len) {
                len = pos[a[i]];
            } else {
                lst[pos[a[i]] = ++len] = a[i];
            }
        }
        for (int i = 1; i <= len; ++i) {
            ++cnt[lst[i]];
        }
    }
    for (int i = 1; i <= m; ++i) {
        cout << cnt[i] << ' ';
    }
    return 0;
}
