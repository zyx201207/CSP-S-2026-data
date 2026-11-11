#include <bits/stdc++.h>
using namespace std;
typedef long long LLD;
const int N = 5e5 + 10;
int n, m;
LLD a[N], s[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r) >> 1;
            if ((i - mid + 1) * a[i] - s[i] + s[mid - 1] <= m) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    printf("%d\n", ans);
    fflush(stdout); fclose(stdin), fclose(stdout);
    return 0;
}