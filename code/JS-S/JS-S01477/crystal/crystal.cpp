#include <bits/stdc++.h>
using namespace std;

 const int N = 5e5 + 10;
 long long a[N];
 int n;
 long long m;

 void solveB() {
    long long cha = a[2] - a[1];
    if (cha == 0) {
        cout << n;
        return;
    }
    double res = sqrt(1.0 * m * 2 / cha + 0.25) - 0.5;
    int cnt = floor(res);
    if (cnt >= n) {
        cout << n;
    } else {
        cout << cnt + 1;
    }
 }

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int f = 0;
    long long cha = a[2] - a[1];
    for (int i = 3; i <= n; i++) {
        if (a[i] - a[i - 1] != cha) {
            f = 1;
            break;
        }
    }
    if (f == 0) {
        solveB();
        return 0;
    }
    reverse(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        long long cnt = 0;
        int j = i;
        while (cnt < m && j < n) {
            j++;
            cnt += a[i] - a[j];
        }
        if (cnt > m) {
            j--;
        }
        int res = j - i + 1;
        ans = max(ans, res);
    }
    cout << ans;

    return 0;
}
