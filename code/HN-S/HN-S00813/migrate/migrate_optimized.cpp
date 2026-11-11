#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T> void _p (T x) { cout << x << ", "; }
template <typename T, typename ...R> void _p (T x, R... r) { _p (x), _p (r...); }
template <typename ...R> void _p (const char *name, R... r) {
    cout << name << ": "; _p (r ...); cout << endl;
}
template <typename T> void _r (const char *name, T *a, int n) {
    cout << name << ": {";
    for (int i = 1 ; i <= n ; i ++) cout << a [i] << ", ";
    cout << "}\n";
}
#define debug(...) _p (#__VA_ARGS__, __VA_ARGS__)
#define debua(a,n) _r (#a, a, n);

const int N = 2e6;
int c, n, d, a [N + 5], f [N + 5], dis [N + 5], ans;
void bfs (int s) {
    memset (dis, 0x3f, sizeof dis);
    memset (f, 0, sizeof f);
    queue <int> q; q. push (s); f [s] = 1; dis [s] = 0;
    while (!q. empty ()) {
        int u = q. front (); q. pop ();
        for (int j = 1 ; j <= n ; j ++) if (abs (a [u] - a [j] <= d)) {
            if (dis [j] > dis [u] + 1)
                dis [j] = dis [u] + 1, f [j] = f [u], q. push (j);
            else if (dis [j] == dis [u] + 1)
                f [j] += f [u];
        }
    }
    debua (f, n);
    debua (dis, n);
    for (int j = 1 ; j <= n ; j ++)
        if (f [j] == 2) ans ++;
}
void Turn () {
    cin >> n >> d; ans = 0;
    for (int i = 1 ; i <= n ; i ++) cin >> a [i];
    for (int i = 1 ; i <= n ; i ++) bfs (i);
    cout << ans << endl;
}

int _; void Init () {
    ios :: sync_with_stdio (0); cin. tie (0); cout. tie (0);
    _ = 1;
    freopen ("migrate1.in", "r", stdin);
    // freopen ("migrate.out", "w", stdout);
    cin >> c >> _;
}

    signed main () { Init ();
    while (_ --> 0)
    Turn (); return 0; }