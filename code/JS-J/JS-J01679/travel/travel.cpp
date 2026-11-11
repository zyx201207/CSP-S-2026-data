#include <bits/stdc++.h>
using namespace std;
string cc1, cc2, ss1, ss2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> cc1 >> cc2 >> ss1 >> ss2;

    if (cc1 == ss1) {
        cout << "1";
        if (cc2[0] == ss2[0] && cc2[1] == ss2[1]) {
            cout << "1";
            if ((cc2[2] > 'C' && ss2[2] > 'C') || (cc2[2] < 'D' && ss2[2] < 'D')) {
                cout << "1";
                if (abs((int)cc2[2] - (int)ss2[2]) == 1) cout << "1" << '\n';
                else cout << "0" << '\n';
            } else {
                cout << "00" << '\n';
            }
        } else {
            cout << "000" << '\n';
        }
    } else {
        cout << "0000" << '\n';
    }
    return 0;
}