#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MAXN = 310;
const int MAXNN = 2e6 + 100;

LL c, t, n, d, x[MAXNN], rt[MAXNN], step;
LL tim[MAXN][MAXN], cnt[MAXN][MAXN];

void solveA()
{
    LL dn = d / step;
//    cerr << dn << endl;
    if (dn <= 1) {
        cout << 0 << '\n';
        return;
    }
    LL len = dn + dn - 1;
    cout << max(0ll, n - 1 - len + 1) << '\n';
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        bool isA = true;
//        cerr << n << endl;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            if (i > 2 && x[i] - x[i - 1] != x[2] - x[1]) {
                isA = false;
            }
        }
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        if (n > 5000 && isA) {
            step = x[2] - x[1];
            solveA();
            continue;
        }
        for (int i = 1; i <= n; i++) {
            tim[i][i] = 0;
            cnt[i][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (x[i] - x[1] > d) {
                break;
            }
            rt[1] = i; // rt[i] == i -> cant fly
        }
        for (int i = 2; i <= n; i++) {
            rt[i] = rt[i - 1];
            for (int j = rt[i] + 1; j <= n; j++) {
                if (x[j] - x[i] > d) {
                    break;
                }
                rt[i] = j;
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                LL j = i + len - 1;
                LL p = i, cc = 0;
                while (p < j) {
                    LL pp = min(rt[p], j);
                    if (pp == p) {
                        break;
                    }
                    p = pp;
                    cc++;
                }
                if (p < j) {
                    tim[i][j] = 1e9;
                    cnt[i][j] = 0;
                    continue;
                }
                tim[i][j] = cc;
                cnt[i][j] = 1;
                p = i, cc = 0;
                while (p < j) {
                    LL pp = min(rt[p], j);
                    if (pp - 1 > p && cc + 1 + tim[pp - 1][j] == tim[i][j]) {
                        cnt[i][j] += cnt[pp - 1][j];
                        if (cnt[i][j] > 2) {
                            break;
                        }
                        if (pp - 2 > p && cc + 1 + tim[pp - 2][j] == tim[i][j]) {
                            cnt[i][j] += cnt[pp - 2][j];
                            if (cnt[i][j] > 2) {
                                cnt[i][j] = 3;
                                break;
                            }
                        }
                    }
                    p = pp;
                    cc++;
                }
            }
        }
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (cnt[i][j] == 2) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
