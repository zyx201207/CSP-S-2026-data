#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 29; i >= 0; --i) {
        int cc = ans | (1 << i);
        int count = 0;
        for (int x : a) {
            if ((x & cc) == cc) {
                count++;
            }
        }
        if (count >= m) {
            ans = cc;
        }
    }
    cout << ans << endl;

    return 0;
}
