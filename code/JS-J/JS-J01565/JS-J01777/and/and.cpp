#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    std::vector<int> tmp;
    for (int i = 29; i >= 0; i--) {
        int cnt = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] & (1 << i)) {
                cnt++;
                tmp.push_back(a[j]);
            }
        }
        if (cnt >= m) {
            ans |= 1 << i;
            a = tmp;
            tmp.clear();
        }
    }
    cout << ans << "\n";
    return 0;
}
