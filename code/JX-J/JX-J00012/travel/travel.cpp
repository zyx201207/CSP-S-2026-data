#include <iostream>
using namespace std;
int c1, c2, s1, s2;
bool a, b, c, d;
char y1, y2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> y1;
    cin >> c2 >> s2 >> y2;
    if (c1 == c2)
        a = 1;
    if (a == 1 && s1 == s2)
        b = 1;
    if (b == 1 && !((y1 <= 'C') ^ (y2 <= 'C')))
        c = 1;
    if (c == 1 && max(y1, y2) - min(y1, y2) == 1)
        d = 1;
    cout << a << b << c << d << endl;
    return 0;
}
