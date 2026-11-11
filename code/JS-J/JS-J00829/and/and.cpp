#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200007;

int n, m;
ll a[N];
bool c[N][22];
// pair<int, int> s[22]; // (i, sum_i)
ll ans = 0;

int k[N];

// bool cmp(pair<int, int> a, pair<int, int> b) {
//     return a.second > b.second;
// }

void dfs(int dep, int lst, ll sum) {
    if (dep == 0) {
        ans = max(ans, sum);
        return;
    }
    for (int i = lst + 1; i <= n; i++) {
        dfs(dep - 1, i, sum & a[i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (m == n) {
        ans = a[1];
        for (int i = 2; i <= n; i++) {
            ans &= a[i];
        }
        cout << ans << "\n";
        return 0;
    }

    if (n <= 30 || m <= 2) {
        dfs(m, 0, 0xffffffff);
        cout << ans << "\n";
        return 0;
    }

    sort(a + 1, a + n + 1); // O(n log n)

    if (m == n - 1) {
        ll sum = 0xffffffff;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j == i)  continue;
                sum &= a[j];
            }
            ans = max(ans, sum);
        }
        cout << ans << "\n";
        return 0;
    }


    if (a[n] <= 0x100000) {
    bool flag = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 21; j++) {
            if ((a[i] >> j & 1) == 0 && a[i] >> j > 0) {
                flag = 0;
                break;
            }
        }
        if (!flag)  break;
    }

    ans = a[n - m + 1];
    cout << ans << "\n";
    return 0;
    }

    // for (int i = 0; i <= 21; i++)  s[i].first = i;

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= 21; j++) {
    //         c[i][j] = a[i] >> j & 1;
    //         s[j].second += c[i][j];
    //     }
    // } // O(n) getting each position's sum

    // sort(s, s + 21, cmp); // O(C)

    cout << ans << "\n";
    return 0;
}