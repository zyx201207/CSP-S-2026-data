#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;
using S = pair<int, char>;
vector<S> v;
vector<S> ans;

void merge() {
    ans.push_back(v[0]);
    // cout << "[" << (*ans.end()).first << "," << (*ans.end()).second << "]" << endl;
    for (int i = 1; i < v.size(); ++i) {
        auto& last = ans[ans.size() - 1];
        // cout << "a=" << a << ";b=" << b << endl;
        if (v[i].second == last.second) {
            last.first += v[i].first;
        } else {
            ans.push_back(v[i]);
        }
    }
}

void judge() {
    vector<S> s1 = ans;
    reverse(s1.begin(), s1.end());
    if (s1 == ans) {cout << 0; return;}
    auto mid = ans.size() / 2;
    int cnt = 0;
    bool x = ans.size() % 2 == 0;
    for (int i = 0, j = ans.size() - 1; x? (i <= mid, j >= mid) : (i < mid, j > mid); ++i, --j) {
        // cout << "comparing i=" << i << ", j=" << j << endl;
        if (ans[i] != ans[j]) {
            // cout << "v[i].first = " << ans[i].first << ", v[j].first = " << ans[j].first << endl;
            cnt += ans[i].first;
        }
    }
    cout << cnt;
}
signed main() {
#ifndef PDEBUG
    auto _1 = freopen("string.in", "r", stdin);
    auto _2 = freopen("string.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int _max = -1e9;
    for (int i = 1; i <= n; ++i) {
        int x; char c; cin >> x >> c;
        v.emplace_back(x, c);
        _max = max(_max, x);
    }

    if (n <= 2000 && _max <= 50) {
        string s1, s2;
        for (auto &c: v) {
            for (int i = 1; i <= c.first; ++i) s1.push_back(c.second);
        }

        s2 = s1;
        reverse(s2.begin(), s2.end());
        if (s1 == s2) {cout << 0; return 0;}
        int mid = s1.size() / 2;
        int cnt = 0;
        for (int i = 0, j = s1.size() - 1; i < mid, j > mid; ++i, --j) {
            if (s1[i] != s1[j]) ++cnt;// cout << "diff at i=" << i << ", j=" << j << endl;
        }
        cout << cnt;
    } else {
        merge();
        judge();
    }
}

/**

3
2 a
2 b
1 c
------
2
2 a
3 a
------
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
**/