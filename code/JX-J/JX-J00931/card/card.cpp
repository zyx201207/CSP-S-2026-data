#include <iostream>
#include <cstdio>
using namespace std;
#define int long long

int n, m;
int a[500005];
int ans[300005];

void f(int x) {
    for (int i = x; i <= n; i++) {
        ans[a[i]]++;
        for (int j = n; j >= i; j--)
            if (a[i] == a[j]) {
                i = j;
                break;
            }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int flag = 0;
    for (int i = 2; i <= n; i++)
        if (a[i - 1] > a[i]) {
            flag = 1;
            break;
        }
    if (!flag) {
        for (int i = n; i >= 1; i--)
            if (!ans[a[i]]) ans[a[i]] = i;
        for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
        return 0;
    }
    if (m == 1) {
        cout << n;
        return 0;
    }
    if (m == 2) {
        for (int i = 1; i <= n; i++)
            if (a[i] == a[n]) ans[a[i]]++;
            else ans[1]++, ans[2]++;
        cout << ans[1] << ' ' << ans[2];
    }
    else {
        for (int i = 1; i <= n; i++) f(i);
        for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    }

    return 0;
}
