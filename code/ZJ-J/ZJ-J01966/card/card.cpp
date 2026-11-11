#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n, m;
signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    vector<int> a(n + 1), ans(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        vector<int> s;
        for (int j = i; j <= n; j++) {
            bool ok = false;
            int k;
            for (k = 0; k < s.size(); k++) {
                if (s[k] == a[j]) {
                    ok = true;
                }
            }
            if (ok)
                while (s.size() != k)
                    s.pop_back();
            else
                s.push_back(a[j]);
        }
        for (auto x : s)
            ++ans[x];
    }
    for (auto x : ans)
        cout << x << ' ';
    return 0;
}