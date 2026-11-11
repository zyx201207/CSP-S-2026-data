#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

char buf[1000000], *p1, *p2;
#define getchar() (p1 == p2 and (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++)
template<typename _Tp>
void read(_Tp& x) {
    x = 0;
    int f = 0, c = getchar();
    while (!isdigit(c)) {
        f |= c == '-', c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + (c & 15), c = getchar();
    }
    x = f ? -x : x;
}

int c, t, n;
long long d, x[2000001];

namespace Sub1 {
    int f[301][301], cnt[301][301];
    vector<int> e[301];
    
    void init() {
        read(n), read(d);
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            read(x[i]);
            for (int j = 1; j < i; ++j) {
                if (x[i] - x[j] <= d) {
                    e[i].push_back(j);
                }
                f[j][i] = INF, cnt[j][i] = 0;
            }
        }
    }
    
    void solve() {
        init();
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            f[i][i] = 0;
            for (int j = i + 1; j <= n; ++j) {
                for (int k : e[j]) {
                    if (k < i) {
                        continue;
                    }
                    if (f[k][j] > 1) {
                        f[k][j] = 1, cnt[k][j] = 1;
                    } else if (f[k][j] == 1) {
                        ++cnt[k][j];
                    }
                    if (f[i][k] + 1 < f[i][j]) {
                        f[i][j] = f[i][k] + 1, cnt[i][j] = 1;
                    } else if (f[i][k] + 1 == f[i][j]) {
                        ++cnt[i][j];
                    }
                    f[k][j] = 1;
                }
                ans += cnt[i][j] == 2;
            }
            
        }
        printf("%lld\n", ans);
    }
}

namespace SubA {
    void solve() {
        read(n), read(d);
        for (int i = 1; i <= n; ++i) {
            read(x[i]);
        }
        long long dif = x[n] - x[n - 1];
        int ans = 0;
        d = d / dif;
        if (d <= 1) {
            puts("0");
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (i + 2 * d - 1 > n) {
                break;
            }
            ++ans;
        }
        printf("%d\n", ans);
    }
}

void solve() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    read(c), read(t);
    while (t--) {
        if (c <= 10) {
            Sub1::solve();
        } else if (c <= 12) {
            SubA::solve();
        }
    }
}

int main() {
    solve();
    return 0;
}