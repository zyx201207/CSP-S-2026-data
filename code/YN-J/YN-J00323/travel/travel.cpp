#include <iostream>

using namespace std;

int c1, s11, c2, s21;
char s12, s22;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s11 >> s12 >> c2 >> s21 >> s22;
    if (c1 != c2) {
        cout << "0000" << endl;
        return 0;
    }
    cout << "1";
    if (s11 != s21) {
        cout << "000" << endl;
        return 0;
    }
    cout << "1";
    if (s12 > s22) {
        swap(s12, s22);
    }
    if ('A' <= s12 && s22 <= 'C') {
        cout << "1" << (s12 + 1 == s22) << endl;
    } else if (s12 == 'D' && s22 == 'F') {
        cout << "11" << endl;
    } else {
        cout << "00" << endl;
    }
    return 0;
}
