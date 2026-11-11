#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef long long ll;
const int N = 200007;

int n, m, ans;
int a[N], dp[N], w[N];

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    if (m == 1) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans = max(ans, a[i]);
        }
        cout << ans << endl;
        return 0;
    }
    if (m == n) {
        cin >> a[1];
        ans = a[1];
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            ans = (ans & a[i]);
        }
        cout << ans;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = a[1];
    w[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
           if (w[j] < m) {
                if ((dp[j] & a[i]) > dp[j]) {
                    dp[i] = (dp[j] & a[i]);
                    w[i] = w[j] + 1;
                }
                else {
                    dp[i] = a[i];
                    w[i] = 1;
                }
           }
        }
    }
    cout << dp[n];

    return 0;
}

/*

a,b,c,d,e


*/
