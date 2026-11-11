#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n, m, a[N], f[N], pre[N], lst[N];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        f[i] = f[pre[i]] + 1;
        if (lst[a[i - 1]] == i - 1) f[i] += f[i - 1];
    }
    for (int i = 1; i <= m; ++i) cout << f[lst[i]] << ' ';
    cout << endl;
    return 0;
}
// 100
// 100 + 100 + 100 + 100 = 400
// qwq akak!!!
