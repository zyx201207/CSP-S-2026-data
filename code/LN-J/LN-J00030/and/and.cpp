#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long arr[N], n, m, sum;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    if (m == 1) {
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, arr[i]);
        }
        cout << ans;
        return 0;
    } else if (m == n) {
        long long sum = arr[1];
        for (int i = 2; i <= n; i++) {
            sum = sum & arr[i];
        }
        cout << sum;
        return 0;
    } else if (m == 2) {
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    ans = max((arr[i] & arr[j]), ans);
                }
            }
        }
        cout << ans;
        return 0;
    } else {
        sort(arr, arr + n);
        cout << arr[n + 1 - m];
        return 0;
    }
}
