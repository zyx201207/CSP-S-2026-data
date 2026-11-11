#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_set<int> a[35];
unordered_set<int> se;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        vector<bool> v;
        while (x) {
            if (x & 1) {
                v.push_back(1);
            } else {
                v.push_back(0);
            }
            x >>= 1;
        }

        for (int j = 0; j < v.size(); j++) {
            if (v[j]) {
                a[j].insert(i);
            }
        }
        se.insert(i);
    }

    int ans = 0;
    for (int i = 31; i >= 0; i--) {
        if (a[i].size() < m) {
            continue;
        }

        int cnt = se.size();
        for (auto j : se) {
            if (!a[i].count(j)) {
                cnt--;
            }
        }
        if (cnt < m) {
            continue;
        }

        unordered_set<int> ff = se;
        for (auto j : ff) {
            if (!a[i].count(j)) {
                se.erase(j);
            }
        }
        ans += (1 << i);

    }

    cout << ans << '\n';
}
