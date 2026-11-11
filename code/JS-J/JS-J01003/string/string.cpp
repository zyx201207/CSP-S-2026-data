#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
ll n, ans;

struct node {
    ll a;
    char c;
}g[N];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> g[i].a >> g[i].c;
    }
    ll l = 1, r = n;
    while (l < r) {
        if (g[l].c != g[r].c) {
            ans += min (g[l].a, g[r].a);
            if (g[l].a > g[r].a) {
                g[l].a -= g[r].a;
                r--;
            } else if (g[l].a < g[r].a) {
                g[r].a -= g[l].a;
                l++;
            } else {
                l++;
                r--;
            }
            //cout << l << " " << r << "\n";
        } else {
            if (g[l].a > g[r].a) {
                g[l].a -= g[r].a;
                r--;
            } else if (g[l].a < g[r].a) {
                g[r].a -= g[l].a;
                l++;
            } else {
                l++;
                r--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
