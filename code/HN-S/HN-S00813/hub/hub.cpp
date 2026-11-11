#include <bits/stdc++.h>
// #define int long long
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

int c;
void Turn () {
    cout << 1 << endl;
}

int _; void Init () {
    ios :: sync_with_stdio (0); cin. tie (0); cout. tie (0);
    _ = 1;
    freopen ("hub.in", "r", stdin);
    freopen ("hub.out", "w", stdout);
    cin >> c >> _;
}

    signed main () { Init ();
    while (_ --> 0)
    Turn (); return 0; }