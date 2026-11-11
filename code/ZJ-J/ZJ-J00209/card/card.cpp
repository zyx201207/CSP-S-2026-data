#include <bits/stdc++.h>
using namespace std;

int cx[100005], n, m, op[100005], ans[100005];
vector<int> v;

int main() {
#ifndef LOCAL
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> op[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cx[j] = -1;
        }
        v.clear();
        for (int j = i; j <= n; j++) {
            if (cx[op[j]] != -1) {
                int t = cx[op[j]];
                for (int i = t; i < v.size(); i++) {
                    cx[v[i]] = -1;
                }
                v.erase(v.begin()+t, v.end());
            }
            v.push_back(op[j]);
            cx[op[j]] = v.size() - 1;
        }
        for (int k : v) {
            ans[k]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}