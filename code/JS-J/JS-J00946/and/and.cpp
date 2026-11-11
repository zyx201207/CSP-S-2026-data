#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int a[N];
int n, m;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 30; i >= 0; i --) {
        vector<int> v;
        for (int j = 1; j <= n; j ++) {
            if ((a[j] >> i) & 1) v.push_back(a[j]);
        }
        if (v.size() < m) continue ;
        long long ans = (1 << i);
        for (int k = i-1; k >= 0; k --) {
            vector<int> t;
            for (auto x : v) {
                if ((x >> k) & 1) t.push_back(x);
            }
            if (t.size() < m) continue ;
            ans += (1 << k);
            v.clear();
            for (auto x : t) v.push_back(x);
        }
        //cerr << i << '\n';
        cout << ans << '\n';
        return 0;
    }
    cout << "0 \n";
    return 0;
}
