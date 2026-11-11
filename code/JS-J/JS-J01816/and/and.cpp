#include <bits/stdc++.h>
using namespace std;

int n, m, a[200010];
bool b[200010];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if ((a[j] & (1 << i)) && !b[j])
                cnt++;
        if (cnt < m)
            continue;
        for (int j = 1; j <= n; j++)
            if (!(a[j] & (1 << i)))
                b[j] = 1;
        ans += 1 << i;
    }
    cout << ans << "\n";
    return 0;
}
