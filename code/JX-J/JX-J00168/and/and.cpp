#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
vector<int> a;

void dfs1(int d, int sum, int id) {
    if (d == m) {
        ans = max(ans, sum);
    } else {
        for (int i = id + 1; i < n; i++) {
            dfs1(d + 1, sum & a[i], i);
        }
    }
}

inline void solve1() {
    dfs1(0, INT_MAX, -1);
    cout << ans;
}

inline void solve2() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                sum &= a[j];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
}

inline void solve3() {
    sort(a.begin(), a.end(), greater<int>());
    cout << a[m - 1];
}

inline void solve4() {
    if (m == 1) {
        cout << (n - 1);
    } else {
        int t = (int)log2(m - 1) + 1;
        cout << ((n - 1) >> t << t);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;

    bool flag3 = true, flag4 = (int)log2(n) == log2(n);
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if ((int)log2(a[i] + 1) != log2(a[i] + 1)) {
            flag3 = false;
        } if (a[i] != i) {
            flag4 = false;
        }
    }

    if (m == n - 1) {
        solve2();
    } else if (flag3) {
        solve3();
    } else if (flag4) {
        solve4();
    } else {
        solve1();
    }

    return 0;
}
