#include <bits/stdc++.h>
using namespace std;

int n, a;
string s;
vector<pair<int, string>> v;

int main() {
#ifndef LOCAL
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> s;
        v.push_back({a, s});
    }
    unsigned long long ans = 0;
    for (int l = 0, r = n-1; l <= r; l++, r--) {
        if (v[l].first < v[r].first) {
            v.insert(v.begin()+r, {v[r].first - v[l].first, v[r].second});
            r++;
            v[r].first = v[l].first;
        }
        if (v[r].first < v[l].first) {
            v.insert(v.begin()+l, {v[r].first, v[l].second});
            r++;
            l++;
            v[l].first = v[l].first - v[r].first;
            l--;
        }
        if (v[l].second != v[r].second) {
            ans += v[l].first;
        }
    }
    cout << ans << endl;
    return 0;
}