#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, cnt, a[N], ans, k;
long long m;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] == a[i - 1]) cnt ++;
    }
    if (cnt == n - 1) {
        cout << n;
        return 0;
    }
    cnt = 0;
    sort(a + 1, a + 1 + n, greater<int> ());
    for (int i = 1; i <= n; i ++) {
        bool flag = false;
        for (int j = i + 1; j <= n; j ++) {
            if (a[i] != a[j]) {
                cnt += a[i] - a[j];
                if (cnt >= m) {
                    ans = max(ans, k + 2);
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            k++;
        }
        k = 0, cnt = 0;
    }
    cout << ans << "\n";
    return 0;
}
