#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
void print(const vector<int>& arr) {
    for (auto &c: arr)cout << c << ' ';cout << endl;}


int a[MAXN];
int main() {
#ifndef PDEBUG
    auto _1 = freopen("crystal.in", "r", stdin);
    auto _2 = freopen("crystal.out", "w", stdout);
#endif
/**
5 5
1 2 4 8 9
**/
    int n, m; cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    sum /= n;
    vector<int> diffs(n);
    for (int i = 0; i < n; ++i) diffs[i] = abs(a[i] - sum);
    // cout << "Diff: " << a[i] << " - " << sum << " = " << a[i] - sum << endl;
    sort(diffs.begin(), diffs.end());
    int cnt = 0, idx = 0;
    print(diffs);
    while (m) {
        // cout << "processing " << idx << ", m=" << m << ", cnt=" << cnt << ", item " << diffs[idx] << endl;
        if (m >= diffs[idx]) m -= diffs[idx], ++cnt, ++idx;
    }

    cout << cnt;

    return 0;
}
