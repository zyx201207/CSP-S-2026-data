#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T> void read(T &x) {
    x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) f = (ch == '-') ? -1 : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar(); x *= f;
}

const int N = 2000005;
int n, nxt[N]; ll d, x[N], f[N][3];

void solve() {
    read(n), read(d);
    for (int i = 1; i <= n; i++) read(x[i]);
    for (int i = n; i >= 1; i--) {
        if (i == n || x[i + 1] > x[i] + d) nxt[i] = -1;
        else if (nxt[i + 1] == -1) nxt[i] = i + 1;
        else {
            nxt[i] = nxt[i + 1];
            while (x[nxt[i]] > x[i] + d) nxt[i]--;
        }
    }
    for (int i = 1; i <= n; i++) f[i][0] = f[i][1] = f[i][2] = 0;
//    for (int i = 1; i <= n; i++) printf("%d%c", nxt[i], " \n"[i == n]);
    
    for (int i = n; i >= 1; i--) {
        int ni = nxt[i];
        if (ni == -1) continue;
        f[i][0] += ni - i;
        int nni = nxt[ni];
        if (nni == -1) continue;
        
        if (ni == i + 1) {
            f[i][0] += f[ni][0];
            f[i][1] += f[ni][1];
        }
        else if (ni == i + 2) {
            f[i][0] += nni - nxt[i + 1];
            if (nxt[i + 1] == nni) {
                f[i][1] += f[ni][0];
                f[i][2] += f[ni][0];
            }
            else if (nxt[i + 1] == nni - 1) {
                f[i][0] += f[ni][0] - (nni - ni);
                f[i][1] += (nxt[i + 1] - ni) + f[ni][1] - f[ni][2];
                f[i][2] += (nxt[i + 1] - ni);
            }
            else {
                f[i][0] += f[ni][0] - (nni - ni);
                f[i][1] += (nxt[i + 1] - ni) + f[ni][1];
                f[i][2] += (nxt[i + 1] - ni);
            }
        }
        else {
            int id1 = ni - 1, id2 = ni - 2;
            assert(nxt[id1] != -1 && nxt[id2] != -1);
            if (nxt[id1] == nni) {
                if (nxt[id2] == nni) continue;
                f[i][1] += f[ni][0] - (nxt[id2] - ni);
                f[i][2] += f[ni][0] - (nxt[id2] - ni);
            }
            else if (nxt[id1] == nni - 1) {
                f[i][0] += f[ni][0] - (nxt[id1] - ni);
                f[i][1] += (nxt[id1] - nxt[id2]);
                f[i][2] += (nxt[id1] - nxt[id2]);
                f[i][1] += f[ni][1] - f[ni][2];
            }
            else {
                f[i][0] += f[ni][0] - (nxt[id1] - ni);
                f[i][1] += (nxt[id1] - nxt[id2]);
                f[i][2] += (nxt[id1] - nxt[id2]);
                f[i][1] += f[ni][1];
            }
        }
        
//        printf("%lld %lld %lld\n", f[i][0], f[i][1], f[i][2]);
    }
    for (int i = n; i >= 1; i--) {
//        if (f[i][1] < 0) {
//            printf("%d %d\n", n, i);
//            printf("%d %lld %lld\n", nxt[i], f[i + 1][1], f[i][1]);
//            printf("%lld %lld %lld\n", f[nxt[i]][0], f[nxt[i]][1], f[nxt[i]][2]);
//            break;
//        }
//        printf("!(%lld) %lld %lld %lld\n", x[i], f[i][0], f[i][1], f[i][2]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += f[i][1];
    printf("%lld\n", ans);
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
//    freopen("migrate6.in", "r", stdin);
//    freopen("my-migrate.out", "w", stdout);
    
    int c, T;
    read(c), read(T);
    while (T--) solve();
    return 0;
}