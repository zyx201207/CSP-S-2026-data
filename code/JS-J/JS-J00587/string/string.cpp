#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, l, r, ln, rn, ans, lnn, rnn;
struct P {
    int a;
    char c;
} s[200005];
char ls, rs;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%lld", &n);
    l = 1;
    r = n;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &s[i].a);
        //s[i].c = getchar();
        cin >> s[i].c;
        m += s[i].a;
    }
    m = (m - 1) / 2 + 1;
    while (n--) {
        if (ln == rn) {
            ls = s[l].c;
            ln += s[l++].a;
        }
        else if (ln < rn) {
            lnn = ln + s[l].a;
            ls = s[l].c;
            if (ls != rs) {
                if (lnn <= rn) {
                    ans += s[l].a;
                }
                else {
                    ans += rn - ln;
                }
            }
            ln = lnn;
            l++;
        }
        else {
            rnn = rn + s[r].a;
            rs = s[r].c;
            if (ls != rs) {
                if (rnn <= ln) {
                    ans += s[r].a;
                }
                else {
                    ans += ln - rn;
                }
            }
            rn = rnn;
            r--;
        }
    }
    printf("%lld", ans);
    return 0;
}
