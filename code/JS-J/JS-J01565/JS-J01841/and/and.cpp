#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, a[200001];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (m == n) {
        int ans = a[1];
        for (int i = 2; i <= n; i++)
            ans &= a[i];
        cout << ans;
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    cout << a[m];
    return 0;
}
