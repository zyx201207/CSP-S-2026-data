#include <iostream>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2, x1, x2;
    string s1, s2;
    char y1, y2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout << "1";
    else return cout << "0000", 0;
    x1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    x2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    if (x1 == x2) cout << "1";
    else return cout << "000", 0;
    y1 = s1[2];
    y2 = s2[2];
    if (
        (y1 < 'D' && y2 < 'D') ||
        (y1 > 'C' && y2 > 'C')
    ) cout << "1";
    else return cout << "00", 0;
    cout << (y1 + 1 == y2 || y1 - 1 == y2);
    return 0;
}
