#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 5;
int n;
ll m, a[MAXN];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll sum = a[1];
    int head = 1, ans = 1;
    for (int i = 2; i <= n; i++) {
        while ((i - head) * a[i] - sum > m) {
            sum -= a[head];
            head++;
        }
        ans = max(i - head + 1, ans);
        sum += a[i];
    }
    cout << ans << endl;
    return 0;
}
