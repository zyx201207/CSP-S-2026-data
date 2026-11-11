#include <iostream>
#define int long long
using namespace std;
const int N = 1e3 + 5;
int a[N];
int dp[N][N];
int n = 0;
int m = 0;
bool isChosen[N] = {};
int ans = -1;
void f(int k, int sum) {
    if (k == m) {
        ans = max(sum, ans);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!isChosen[i]) {
            isChosen[i] = true;
            f(k + 1, sum & a[i]);
            isChosen[i] = false;
        }
    }
}
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        isChosen[i] = true;
        f(1, a[i]);
        isChosen[i] = false;
    }
    cout << ans << endl;
    return 0;
}