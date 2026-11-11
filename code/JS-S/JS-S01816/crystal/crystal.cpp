#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5;
int n, m;
int a[N + 10], sum[N + 10];
bool check(int x) {
    for (int i = n; i >= x; i --) {
        if (a[i] * (x - 1) - (sum[i - 1] - sum[i - x]) <= m) {
           return true;
        }
    }
    return false;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++) {
        sum[i] = sum[i - 1] + a[i];
    }

    int l = 1, r = n;
    int mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;

    }
    cout << l << "\n";
    return 0;
}
