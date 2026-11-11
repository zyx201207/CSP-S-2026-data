#include <iostream>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    char a1, a2, b1, b2, b3, c1, c2, d1, d2, d3;
    int s1 = 0, s2 = 0;
    //cin >> a1 >> a2 >> tmp >> b1 >> b2 >> b3 >> tmp >> c1 >> c2 >> tmp >> d1 >> d2 >> d3;
    cin >> a1 >> a2 >> b1 >> b2 >> b3 >> c1 >> c2 >> d1 >> d2 >> d3;
    if (a1 == c1 && a2 == c2) {
        cout << 1;
    } else {
        cout << "0000";
        return 0;
    }

    if (b1 == d1 && b2 == d2) {
        cout << 1;
    } else {
        cout << "000";
        return 0;
    }

    if (b3 == 'A' || b3 == 'B' || b3 == 'C') {
        s1++;
    } else {
        s2++;
    }
    if (d3 == 'A' || d3 == 'B' || d3 == 'C') {
        s1++;
    } else {
        s2++;
    }
    if (s1 == 2 || s2 == 2) {
        cout << 1;
    } else {
        cout << "00";
        return 0;
    }

    if (abs((int)b3 - (int)d3) == 1) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}
