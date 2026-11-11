#include <bits/stdc++.h>
#define int long long
const int N = 5e5 + 10;
using namespace std;
int a[N], sum[N], pre[N];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
//    return 0;
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i ++) {
        a[i - 1] = a[i] - a[i - 1]; //cha zhi
    }
//    for (int i = n; i >= 1; i ++)
//            pre[i] = pre[i + 1] + a[i];
    for (int i = 1; i < n; i ++) {
        pre[i] = pre[i - 1] + a[i];
        sum[i] = a[i] * i;
    }
    for (int i = 1; i < n; i ++)
        sum[i] = sum[i - 1] + sum[i];
    int j = 1;
    int maxn = 0;
    int k = 0;
//    for (int i = n; i >= 1; i ++) {
//        while (pre[j] - pre[i] <= m && j > 1) {
//
//            j --;
//        }
//        maxn = max(i - j, maxn);
//    }
    for (int i = 1; i < n; i ++) {
//        cout << '#' << k << ' ' << a[i] << endl;
        k = k + (j - 1) * a[i];
//        cout << '#' << k << ' ' << a[i] << j - 1 << endl;
        while (sum[i] - k > m && j < i) {
                k += pre[i] - pre[j - 1];
                j ++;
        }
        maxn = max(maxn, i - j + 2);
    }
    cout << maxn;
    return 0;
}
