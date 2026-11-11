#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << "1";
        if (s1.substr(0, 2) == s2.substr(0, 2)) {
            cout << "1";
            char mod1, mod2;
            if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') mod1 = 'd';
            else mod1 = 'u';
            if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') mod2 = 'd';
            else mod2 = 'u';

            if (mod1 == mod2) {
                cout << "1";
                char number1 = s1[2];
                char number2 = s2[2];
                if (mod1 == 'u') {
                    if ((number1 == 'D' && number2 == 'F') || (number1 == 'F' && number2 == 'D')) cout << "1";
                    else cout << "0";
                } else {
                    if ((number1 == 'A' && number2 == 'B') || (number1 == 'B' && number2 == 'A') || (number1 == 'B' && number2 == 'C') || (number1 == 'C' && number2 == 'B')) cout << "1";
                    else cout << "0";
                }
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
    return 0;
}
