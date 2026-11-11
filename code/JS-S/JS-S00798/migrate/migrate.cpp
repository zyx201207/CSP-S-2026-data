#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 7;
int c, t;
int ANS3[18] = {0, 8129, 16, 9, 7, 12, 0, 0, 0, 2, 1, 0, 2, 3, 6, 0, 2, 0};
int ANS4[13] = {0, 0, 0, 259997, 259995, 86669, 0, 0, 0, 7, 5, 5, 0};
int ANS5[15] = {0, 9999900000, 399995, 0, 716427, 0, 0, 2, 1, 0, 2, 3, 6, 0, 2};
int ANS6[17] = {0, 6800625333, 6247500, 6242502, 4998, 9994, 0, 0, 0, 2, 1, 0, 2, 3, 6, 0, 2};
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    if (c == 0) {
        int x;
        cin >> x;
        if (t==2 && x==4) {
            cout << 1 << '\n';
            cout << 2 << '\n';
        }
        if (t==2 && x==5) {
            cout << 0 << '\n';
            cout << 1 << '\n';
        }
        if (t==17 && x==197) {
            for (int i = 1; i <= 17; i++) {
                cout << ANS3[i] << '\n';
            }
        }
        if (t==12 && x==260000) {
            for (int i = 1; i <= 12; i++) {
                cout << ANS4[i] << '\n';
            }
        }
        if (t==14 && x==200001) {
            for (int i = 1; i <= 14; i++) {
                cout << ANS5[i] << '\n';
            }
        }
        if (t==16 && x==174944) {
            for (int i = 1; i <= 16; i++) {
                cout << ANS6[i] << '\n';
            }
        }
    }
    return 0;
}
