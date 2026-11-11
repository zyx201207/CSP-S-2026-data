#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 5;
int n, m;
ll a[N], c[N], mi = INT_MAX, sum, ans;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll tot = 0, tt = 0;
    for (int i = 2; i <= n; i++) {
        c[i] = a[i] - a[i - 1];
        if (c[i] < mi) {
            mi = c[i];
            tot = i;
            tt = i;
        }
    }
    ll tmp = 2;
    sum = mi;
    if (tot >= 2) c[tot - 1] += mi;
    while (sum <= m) {
        if ((c[tot - 1] <= tmp * c[tt + 1] && tot != 2) || tt == n) {
            if (sum + c[tot - 1] > m) {
                cout << tmp << "\n";
                return 0;
            }
            sum += c[tot - 1];
            c[tot - 2] += c[tot - 1];
            tot--;
            tmp++;
        } else if (c[tot - 1] > tmp * c[tt + 1] || tot == 2) {
            if (sum + tmp * c[tt + 1] > m) {
                cout << tmp << "\n";
                return 0;
            }
            sum += tmp * c[tt + 1];
            c[tot - 1] += c[tt + 1];
            tt++;
            tmp++;
        }

    }
    cout << tmp << "\n";
    //for (int i = 1; i <= n; i++) cout << c[i] << " ";
    return 0;
}
