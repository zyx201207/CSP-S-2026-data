#include<bits/stdc++.h>
#define FILENAME "card"
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans(m);
    vector<int> cur;
    for (int i = 0; i < n; i++) {
        cur.clear();
        for (int j = i; j < n; j++) {
            auto pos = lower_bound(cur.begin(), cur.end(), a[j]);
            if(pos == cur.end() || *pos != a[j]) cur.push_back(a[j]);
            else {
                for (int k = 0; k < cur.end() - pos; k++) cur.pop_back();
            }
        }
        for (auto e : cur) {
            ans[e - 1]++;
        }
    }
    for (auto e : ans) cout << e << ' ';
}

int main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}