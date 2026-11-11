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

const int N = 100;
int a [N + 5];
mt19937 RND (time (0));
int ranint (int l, int r) {
    return l + RND () % (r - l + 1);
}
void Turn () { 
    cout << 13 << " " << 1 << endl;
    int d = ranint (1, N * 100);
    cout << N << " " << d << endl;
    a [0] = 0;
    for (int i = 2 ; i <= N ; i ++) a [i] = ranint (a [i - 1] + 1, a [i - 1] + d);
    for (int i = 1 ; i <= N ; i ++) cout << a [i] << " ";
    cout << endl;
}

int _; void Init () {
    ios :: sync_with_stdio (0); cin. tie (0); cout. tie (0);
    _ = 1;
    freopen ("migrate.in", "w", stdout);
}

    signed main () { Init ();
    while (_ --> 0)
    Turn (); return 0; }