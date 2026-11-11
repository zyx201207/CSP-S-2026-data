#include<bits/stdc++.h>
using namespace std;
string a1, a2, b1, b2;
string ans = "";
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a1 >> a2 >> b1 >> b2;
    if (a1 == b1) {
        ans = ans + "1";
        if (a2[0] == b2[0] && a2[1] == b2[1]) {
            ans = ans + "1";
            if (a2[2] <= 'C' && b2[2] <= 'C' || a2[2] > 'C' && b2[2] > 'C') {
                ans = ans + "1";
                if (abs(a2[2] - b2[2]) == 1) {
                    ans = ans + "1";
                }
                else {
                    ans = ans + "0";
                }
            }
            else {
               for (int i = 1; i <= 2; i++) {
                    ans = ans + "0";
               }
            }
        }
        else {
            for (int i = 1; i <= 3; i++) {
                ans = ans + "0";
            }
        }
    }
    else {
        for (int i = 1; i <= 4; i++) {
            ans = ans + "0";
        }
    }
    cout << ans;

    return 0;
}
