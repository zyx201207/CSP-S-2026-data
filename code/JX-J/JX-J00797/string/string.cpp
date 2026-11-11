#include <iostream>
#include <cmath>
using namespace std;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long n, x, ci[200000], sum = 0;
    int L;
    cin >> n;
    char c, ch[200000];
    string s;
    for (int i = 0; i < n; i++) {
        cin >> x >> c;
        L += x;
        ci[i] = x;
        ch[i] = c;
    }
    int cL = L / 2, r = n - 1;
    for (int l = 0; r && r > l; l++) {
        char lc = ch[l];
        long ln = ci[l],
            a = ln,
            i = l;
        while (a && r >= 0) {
            long rn = ci[r], notc = lc != ch[r];
            if (r == l) {
                //cout << rn << r << "rl";
                a = 0;
                break;
            }
            if (rn > a) {
                int df = ln / 2;
                ci[r] -= df;
                if (notc) sum += df;
                a = 0;
                //cout << sum << l << r << notc << " " << rn << ">" << df << endl;
            } else if (rn < a) {
                int df = ln / 2;
                ci[l] -= df;
                a -= df;
                if (notc) sum += df;
                //cout << sum << l << r << notc << " " << rn << "<" << endl;
            } else {
                if (notc) sum += rn;
                a = 0;
                //cout << sum << " " << l << r << notc << " " << rn << "=" << endl;
            }
            r--;
        }
    }
    cout << sum;
    return 0;
}

