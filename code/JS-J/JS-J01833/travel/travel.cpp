#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main() {
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {
        cout << "0000" << endl;
        return 0;
    }
    cout << "1";
    int a = (s1[0] - 48) * 10 + s1[1] - 48;
    int b = (s2[0] - 48) * 10 + s2[1] - 48;
    if (a != b) {
        cout << "000" << endl;
        return 0;
    }
    cout << "1";
    char seat1 = s1[2],  seat2 = s2[2];
    if ('D'==seat1&&seat1=='F'&&'D'==seat2&&seat2=='F') {
        cout << "11" << endl;
        return 0;
    }
    if ('A'<=seat1&&seat1<='C'&&'A'<=seat2&&seat2<='C') {
        cout << "1";
        a = seat1 - 65, b = seat2 - 65;
        if (a + 1 == b || a - 1 == b) {
            cout << "1" << endl;
        }
        else cout << "0" << endl;
        return 0;
    }
    cout << "00";
    return 0;
}