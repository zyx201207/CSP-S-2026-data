#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[20005];
long long solve(int l, int cnt, long long a) {
    if (n - l + cnt < m) return 0;
    if (n - l + cnt == m) {
        for (int i = l; i < n; i++) {
            a &= arr[i];
        }
        return a;
    }
    if (l == n && cnt == m) return a;
    if (l == n && cnt != m) return 0;
    if (cnt == m) return a;
    int a1 = 0, a2 = 0;
    if (cnt == 0) {
        a1 = solve(l + 1, cnt, a); a2 = solve(l + 1, cnt + 1, arr[l]);
    }
    else {
        a1 = solve(l + 1, cnt, a); a2 = solve(l + 1, cnt + 1, a &= arr[l]);
    }
    a = max(a1, a2);
    return a;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solve(0, 0, 0);
    return 0;
}
