#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
#define int long long

int b[200005];
int a[35][200005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int cnt = 0;
        while (x) {
            a[cnt][i] = x % 2;
            cnt++;
            x /= 2;
        }
        b[i] = 1;
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) cnt += (b[j] && a[i][j]);
        if (cnt < m) continue;
        for (int j = 1; j <= n; j++)
            if (!a[i][j]) b[j] = 0;
        int sum = 1;
        for (int j = 1; j <= i; j++) sum *= 2;
        ans += sum;
    }
    cout << ans;

    return 0;
}
