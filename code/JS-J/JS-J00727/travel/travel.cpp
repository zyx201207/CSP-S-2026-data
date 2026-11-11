#include<bits/stdc++.h>
using namespace std;

void solve() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c) {
        printf("1");
        if (b[0] == d[0] && b[1] == d[1]) {
            printf("1");
            if ((b[2] - 'A' <= 2 && d[2] - 'A' <= 2) || (b[2] - 'A' > 2 && d[2] - 'A' > 2)) {
                printf("1");
                if (abs(b[2] - d[2]) == 1) {
                    printf("1");
                } else {
                    printf("0");
                }
            } else {
                printf("00");
            }
        } else {
            printf("000");
        }
    } else {
        printf("0000");
    }

}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
