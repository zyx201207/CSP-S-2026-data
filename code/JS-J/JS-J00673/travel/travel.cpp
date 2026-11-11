#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    if (a1 != b1) {
        cout << "0000";
    } else {
        cout << 1;

        if(a2.substr(0, 2) != b2.substr(0, 2)) {
            cout << "000";
        } else {
            cout << 1;

            char a = a2[2], b = b2[2];
            bool flag_a = false, flag_b = false;

            if (a == 'A' || a == 'B' || a == 'C') {
                flag_a = true;
            }

            if (b == 'A' || b == 'B' || b == 'C') {
                flag_b = true;
            }

            if (!(flag_a == true && flag_b == true || flag_a == false && flag_b == false)) {
                cout << "00";
            } else {
                cout << 1;

                int order_a = (a - 'A' + 1), order_b = (b - 'A' + 1);
                if (a == 'D') {
                    a++;
                }

                if (b == 'D') {
                    b++;
                }

                if (abs(a - b) == 1) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
        }
    }

    cout << endl;

    return 0;
}
