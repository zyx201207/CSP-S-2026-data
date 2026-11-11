#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6;
int c, n, d, a [N + 5], ans, le [N + 5], rt [N + 5];
int f [N + 5], dis [N + 5], sum [N + 5];
void bfs (int s) {
    f [s] = 1; dis [s] = 0; sum [0] = 1; int r = s;
    for (int i = s - 1 ; i >= 1 ; i --) {
        while (a [r] > a [i] + d) {
            sum [dis [r]] -= f [r];
            r --;
        }
        if (r == i) break;
        dis [i] = dis [r] + 1;
        f [i] = min (3ll, sum [dis [i] - 1]);
        if (f [i] == 2) ans ++;
        sum [dis [i]] += f [i];
    }
    for (int i = 1 ; i < s ; i ++)
        sum [dis [i]] = 0;
}
void Turn () {
    cin >> n >> d; ans = 0;
    for (int i = 1 ; i <= n ; i ++) cin >> a [i];

    if (n <= 5000) {
        for (int i = 1 ; i <= n ; i ++) bfs (i);
        cout << ans << endl;
        return ;
    }

    int l = 1, r = n;
    for (int i = 1 ; i <= n ; i ++) {
        while (a [i] - a [l] > d) l ++;
        le [i] = l;
    } 
    for (int i = n ; i >= 1 ; i --) {
        while (a [r] - a [i] > d) r --;
        rt [i] = r;
    }
    for (int i = 1 ; i <= n ; i ++) {
        int x = i, s = 1, t = 0, lstx = i + 1;
        while (1) {
            int ns = ((rt [le [x]] > x + 1 && rt [le [x]] < lstx) ? 3 : (rt [le [x]] > x ? s + t : s));
            int nt = le [x] == x - 1 ? 0 : (rt [le [x] + 1] > x ? min (3ll, s + t) : s);
            if (s == 1 && t == 1) {
                int R = (int) (upper_bound (rt + 1, rt + n + 1, x + 1) - rt);
                int L = (int) (lower_bound (rt + 1, rt + n + 1, x + 1) - rt);
                R = min (R, x);
                if (L > 0) {
                    ans += R - L;
                }
            }
            if (s == 2) {
                int R = (int) (upper_bound (rt + 1, rt + n + 1, x) - rt);
                int L = (int) (lower_bound (rt + 1, rt + n + 1, x) - rt);
                R = min (R, x);
                if (L > 0) {
                    ans += R - L;
                }
            }
            if (x == le [x]) break;
            lstx = x;
            x = le [x];
            s = ns;
            t = nt;
        }
    }
    cout << ans << endl;
}

int _; void Init () {
    ios :: sync_with_stdio (0); cin. tie (0); cout. tie (0);
    _ = 1;
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    cin >> c >> _;
}

    signed main () { Init ();
    while (_ --> 0)
    Turn (); return 0; }

/*
0 1
6 3
3 6 7 8 9 10
*/