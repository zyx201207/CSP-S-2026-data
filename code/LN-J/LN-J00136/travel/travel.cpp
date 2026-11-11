#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) {
        cout << 1;
        char s1a = s1[0], s1b = s1[1];
        char s2a = s2[0], s2b = s2[1];
        if(s1a == s2a && s1b == s2b) {
            cout << 1;
            char s1c = s1[2], s2c = s2[2];
            if(((s1c == 'A' || s1c == 'B' || s1c == 'C') && (s2c == 'A' || s2c == 'B' || s2c == 'C')) ||
            ((s1c == 'D' || s1c == 'F') && (s2c == 'D' || s2c == 'F'))) {
                cout << 1;
                if(((s1c == 'D' || s1c == 'F') && (s2c == 'D' || s2c == 'F'))) {
                    cout <<1;
                } else if((s1c == 'A' && s2c == 'B') || (s1c == 'B' && s2c == 'A') || (s1c == 'B' && s2c == 'C') ||(s1c == 'C' && s2c == 'B')) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
        return 0;
    }

    return 0;
}
