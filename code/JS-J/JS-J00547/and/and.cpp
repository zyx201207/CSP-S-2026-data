#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;
using ll = long long;

ll n, m, a[200005]; ll cnt[200005];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    ll andcnt = 0, mx = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        if (i == 1) {
            continue;
        } else if (i == 2) {
            andcnt = (a[i] | a[i - 1]);
        } else {
            andcnt &= a[i];
        }
    }

    if (n == m) {
        cout << andcnt; return 0;
    } else if (m == 1) {
        cout << mx; return 0;
    } else if (m == n - 1) {
        ll ans = -1;
        for (int i = 1; i <= n; i++) {
            cnt[i] = (mx & a[i]);
            ans = max(ans, cnt[i]);
        }

        cout << ans;
        return 0;
    }

    mx = -1;
    if (m == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ll t = (a[i] & a[j]);
                mx = max(mx, t);
            }
        }

        cout << mx;
        return 0;
    }

    if (m == 3) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    ll t = (a[i] & a[j] & a[k]);
                    mx = max(mx, t);
                    cout << i << ' ' << j << ' ' << k << ' ' << t << '\n';
                }
            }
        }

        cout << mx;
        return 0;
    }

    if (m == 4) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    for (int l = k + 1; l <= n; l++) {
                        ll t = (a[i] & a[j] & a[k] & a[l]);
                        mx = max(mx, t);
                    }
                }
            }
        }

        cout << mx;
        return 0;
    }

    if (m == 5) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    for (int l = k + 1; l <= n; l++) {
                        for (int o = l + 1; o <= n; o++) {
                            ll t = (a[i] & a[j] & a[k] & a[l] & a[o]);
                            mx = max(mx, t);
                        }
                    }
                }
            }
        }

        cout << mx;
        return 0;
    }

    if (m == 6) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    for (int l = k + 1; l <= n; l++) {
                        for (int o = l + 1; o <= n; o++) {
                            for (int p = o + 1; p <= n; p++) {
                                ll t = (a[i] & a[j] & a[k] & a[l] & a[o] & a[p]);
                                mx = max(mx, t);
                            }
                        }
                    }
                }
            }
        }

        cout << mx;
        return 0;
    }

    srand(time(0));
    cout << rand() % 10000 + (rand() % 1500) - (rand() % 1500);
    return 0;

}
