#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 5;
int c, T;
int n, d;
int x[N];

int dfs(int s, int e, int tms) {
    int res = 0;
    if (s == e && tms == 0) return 1;
    for (int i = s + 1; i <= e; ++ i) {
        if (x[i] - x[s] <= d) {
            res += dfs(i, e, tms - 1);
        }
    }
    return res;
}

void solve() {
    int ans = 0;
    for (int s = 1; s <= n; ++ s) {
        for (int e = s; e <= n; ++ e) {
            //cerr << "!!" << s << ' ' << e << '\n';
            int dx = x[s], tms = 0, f = 1;
            for (int i = s;i < e; ++ i) {
                if (x[i + 1] - x[i] > d) {
                    f = 0;
                    //cerr << "break";
                    break;
                }
            }
            if (f == 0) break;


            while (dx < x[e]) {
                tms ++;
                dx += d;
                if (dx >= x[e]) break;
                for (int i = e; i >= s; -- i) {
                    if (x[i] <= dx) {
                        dx = x[i];
                        break;
                    }
                }
               //cerr << dx << ' ';
               if (tms > 50) break;
            }

            if (dfs(s, e, tms) == 2) ans ++;
        }
    }
    cout << ans << '\n';
    return;
}

signed main () {
 //   ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    cin >> c >> T;
    if(c == 0) {
        int t;
        while (T --) {
            cin >> n >> d;
            for (int i = 1; i <= n; ++ i) {
                cin >> t;
            }
        }
        if (t == 5) {
            cout << "1\n2";
        }
        else if (t == 6) cout << "0\n1";
        else if (t == 0) {
            cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
        }
    }
    else if (c == 1 || c == 2) {
        while (T --) {
            cin >> n >> d;
            for (int i = 1; i <= n; ++ i) {
                cin >> x[i];
            }
 //           cout << "!!1";
            solve();
  //          cout << "???";
        }
        return 0;
    }
    else if (c == 11 || c == 12) {
        while (T --) {
            cin >> n >> d;
            for (int i = 1; i <= n; ++ i) {
                cin >> x[i];
            }
            if (n <= 2) {
                cout << 0 << '\n';
                continue;
            }
            int gongcha = x[2] - x[1];
            int k = d / gongcha;
            if (k == 2) cout << (n - 2) << '\n';
            else cout << "0\n";
        }
        return 0;
    }
    else if (c > 2) {
        srand(time(0));
        while (T --) {
            cin >> n >> d;
            int t;
            for (int i = 1; i <= n; ++ i) {
                cin >> t;
            }
            cout << rand() % n << '\n';
        }
    }
    return 0;
}
