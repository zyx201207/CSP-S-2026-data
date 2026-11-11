#include <iostream>
using namespace std;

const int MAXN = 2e6 + 5;
typedef long long ll;
int T, n; ll d, x[MAXN], ans;
int rm[MAXN], lm[MAXN], ldd[MAXN], rdd[MAXN];
int lc[MAXN], rc[MAXN];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (cin >> T >> T; T --; ) {
        cin >> n >> d; ans = 0;
        for (int i = 1; i <= n; i ++) cin >> x[i];
        for (int i = 1; i <= n; i ++) ldd[i] = rdd[i] = lc[i] = rc[i] = 0;
        for (int i = 1, j = 1; i <= n; i ++) {
            while (j < n && x[j + 1] - x[i] <= d) j ++;
            rm[i] = j;
        } for (int i = n, j = n; i >= 1; i --) {
            while (j > 1 && x[i] - x[j - 1] <= d) j --;
            lm[i] = j;
        } for (int i = 1; i <= n; i ++) {
            ldd[i] += 1; int j = rm[i];
            if (lm[j] == i) ldd[j] += ldd[i];
        } for (int i = n; i >= 1; i --) {
            rdd[i] += 1; int j = lm[i];
            if (rm[j] == i) rdd[j] += rdd[i];
        } for (int i = 1; i <= n; i ++) {
            lc[rm[i]] ++;
        } for (int i = n; i >= 1; i --) {
            rc[lm[i]] ++;
        }

        //if (T == 0) {
        //    cerr << ' ' << n << ' ' << d << endl;
        //    for (int i = 1; i <= n; i ++) cerr << ' ' << x[i];
        //    cerr << endl;
        //    for (int i = 1; i <= n; i ++) cerr << ' ' << lm[i]; cerr << endl;
        //    for (int i = 1; i <= n; i ++) cerr << ' ' << rm[i]; cerr << endl;
        //}

        for (int m1 = 2, m2 = 3; m2 < n; m1 ++, m2 ++) {
            int r = rm[m2], l = lm[m1];
            if (l == m1 || r == m2) continue;
            if (l == m2 || r == m1) continue;
            //cerr<<l<<", " << m1 << ", " << m2 << ", " << r << endl;
            ll dv = 0;
            if (rm[l] == m2 && lm[r] == m1) dv += 1ll * ldd[l] * rdd[r];//,cerr<<"1+="<<ldd[l]*rdd[r]<<endl;
            int pr = max(0, rc[m1] - (lm[r] == m1) - (lm[m1] == m1) - (lm[m2] == m1));
            int pl = max(0, lc[m2] - (rm[l] == m2) - (rm[m1] == m2) - (rm[m2] == m2));
            if (rm[l] == m2) dv += 1ll * ldd[l] * pr;//, cerr << "2+="<<ldd[l]*pr<<endl;
            if (lm[r] == m1) dv += 1ll * rdd[r] * pl;//, cerr << "3+="<<rdd[r]*pl<<endl;
            dv += 1ll * pl * pr;//,cerr<<"4+="<<pl*pr<<endl;
            //cerr << "m[" << m1 << ", " << m2 << "]: += " << dv << endl;
            ans += dv;
        }

        cout << ans << '\n';
    } return 0;
}
