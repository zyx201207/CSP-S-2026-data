#include <iostream>
#include <string>
using namespace std;
string c1, s1, c2, s2;
int a(char a, char b) {
    int c = a - b;
    if (c >= 0) return c;
    return -c;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    bool flag0 = true;
    if (c1 == c2) cout << 1;
    else {
        cout << "0000";
        return 0;
    }
    bool flag = true;
    for (int i = 0; i < 2; i++) {
        if (s1[i] != s2[i]) {cout << "000";return 0;}
    }
    cout << 1;
    bool flag3 = true;
    if (s1[2] <='C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D') {
        cout << 1;
    } else {
        cout << "00";
        return 0;
    }
    if (a(s1[2], s2[2]) == 1) cout << 1;
    else cout << 0;
    return 0;
}
