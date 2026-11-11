#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

const int N = 2e6 + 10;
int n, d;
int diff;
int a[N];

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int gunmu, t;
    cin >> gunmu >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        diff = a[2] - a[1];
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            int dis = (i - 1) * diff;
            if ((dis % d != 0) && dis / d == 1) {
                ans += (n - i + 1);
            }
        }
        cout << ans;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}