# include <algorithm>
# include <iostream>
# include <vector>

using std::cin;
using std::cout;
using std::vector;

typedef long long ll;

struct node {
    bool bil{false}, bir{false};
    int l{-1}, r{-1};
    int cntl{0}, cntr{0};
    int selfl{0}, selfr{0};

    void output() {
        cout << l << "(" << bil << ")=" << cntl << ", " << r << "(" << bir << ")=" << cntr << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::freopen("migrate.in", "r", stdin);
    std::freopen("migrate.out", "w", stdout);

    // int nn;
    // cin >> nn;
    // ll lst = 0;
    // for (int i = 0; i < nn; ++i) {
    //     ll a;
    //     cin >> a;
    //     cout << a - lst << "\n";
    //     lst = a;
    // }
    // return 0;

    int tid, T;
    cin >> tid >> T;

    while (T--) {
        int n;
        ll lim;
        cin >> n >> lim;

        vector<ll> pos(n);
        for (auto &x: pos) {
            cin >> x;
        }

        vector<node> info(n);

        auto output = [&]() {
            for (int i = 0; i < n; ++i) {
                cout << i << " at " << pos[i] << ": ";
                info[i].output();
            }
        };

        int cur = 0;
        for (int i = 0; i < n; ++i) {
            while (cur < n && (pos[cur] - pos[i] <= lim)) {
                cur += 1;
            }

            info[i].r = cur - 1;
        }

        cur = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            while (cur >= 0 && (pos[i] - pos[cur] <= lim)) {
                cur -= 1;
            }

            info[i].l = cur + 1;
        }

        for (int i = 0; i < n; ++i) {
            if (info[i].r != i) {
                info[i].bir = info[info[i].r].l == i;
                info[info[i].r].cntl += 1;  // chk bir? 
            }
            if (info[i].l != i) {
                info[i].bil = info[info[i].l].r == i;
                info[info[i].l].cntr += 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            info[i].selfl = info[i].cntl;
            info[i].selfr = info[i].cntr;
        }

        for (int i = 0; i < n; ++i) {
            if (info[i].bir) {
                info[info[i].r].cntl += info[i].cntl;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (info[i].bil) {
                info[info[i].l].cntr += info[i].cntr;
            }
        }

        // output(); //   aeifa;dslk

        ll ans = 0;

        for (int u = 0; u < n; ++u) {
            int mid = info[u].r, v = info[mid].r;
            if ((v == mid) | (mid == u + 1)) {
                continue;
            }

            ans += std::upper_bound(pos.begin() + mid, pos.begin() + v + 1, pos[mid - 1] + lim)
                   - std::upper_bound(pos.begin() + mid, pos.begin() + v + 1, pos[mid - 2] + lim);
        }  // incorrect. cnt needed to be counted. time not enought:(

        for (int u = 0; u < n; ++u) {
            if (info[u].l == u) {
                continue;
            }

            if (!info[u].bil || info[u].bir || info[info[u].r].l != u - 1) {
                continue;
            }

            if (info[u - 1].l != info[u].l) {
                ans += info[info[u].r].cntr;
            } else {
                ans += 1ll * (info[info[u - 1].l].cntl + 1) * (info[info[u].r].cntr + 1) - 1;
            }
        }

        for (int u = 0; u < n; ++u) {
            if (info[u].r == u) {
                continue;
            }

            if (!info[u].bir || info[u].bil || info[info[u].l].r != u + 1) {
                continue;
            }

            if (info[u + 1].r == info[u].r) {
                continue;
            }

            ans += info[info[u].l].cntl;
        }

        cout << ans << "\n";
    }

    return 0;
}
//1 1
// 5 3
// -3 0 2 3 4

// 1 1
// 10 3
// 0 3 6 8 10 11 12 13 15 18
