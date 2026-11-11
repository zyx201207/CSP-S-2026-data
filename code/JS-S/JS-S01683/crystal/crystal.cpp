#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], sum[N], head, tail;
pair <int, int> p[N];
bool check(int x) {
    head = 1, tail = 0;
    for (int i = 1; i <= n; i++) {
        while (head <= tail && p[tail].first <= a[i]) tail--;
        while (head <= tail && p[head].second < i - x + 1) head++;
        p[++tail] = {a[i], i};
        if (i >= x && p[head].first * x - (sum[i] - sum[i - x]) <= m)
            return true;
    }
    return false;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << r << endl;
    return 0;
}