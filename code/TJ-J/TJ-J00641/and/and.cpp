#include <bits/stdc++.h>

using namespace std;

using LL = long long;

int n, m, x, ans;
vector<int> a, b;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 29; i >= 0; i--) {
        int cnt = 0;
        b.clear();
        for (auto x : a) {
            if ((x >> i) & 1) {
                cnt++;
                b.push_back(x);
            }
        }
        if (cnt >= m) {
            ans += (1 << i);
            a = b;
        }
    }
    cout << ans << endl;

    return 0;
}
