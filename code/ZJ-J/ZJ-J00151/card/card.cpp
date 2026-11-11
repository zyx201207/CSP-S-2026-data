#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[500005];
int cnt[300005];

inline void solve(int l) {
    if (l == n + 1) {
        cnt[a[l]]++;
        return;
    }
    int last = 0;
    for (int i = l + 1; i <= n; i++) {
        if (a[l] == a[i]) {
            last = i;
        }
    }
    if (last != 0) {
        solve(last + 1);
        cnt[a[l]]++;
        return;
    } else {
        solve(l + 1);
        cnt[a[l]]++;
    }
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        solve(i);
    }

    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << ' ';
    }
}
