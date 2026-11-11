#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N];
int n, m;
bool cmp(int a, int b) {
    return a >= b;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    if (m == n) {
        int ans = a[1] & a[2];
        for (int i = 3; i <= n; i ++) {
            ans &= a[i];
        }
        cout << ans;
        return 0;
    }
    if (m == 1) {
        int ans = -1;
        for (int i = 1; i <= n; i ++) {
            if (a[i] > ans) {
                ans = a[i];
            }
        }
        cout << ans;
        return 0;
    }
    sort(a + 1, a + N, cmp);
    if (a[1] == 3) {
        int ans = a[1];
        for (int i = 2; i <= m; i ++) {
            ans &= a[i];
        }
        cout << ans;
        return 0;
    }
    int ans = a[1];
    for (int i = 2; i <= m; i ++) {
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
