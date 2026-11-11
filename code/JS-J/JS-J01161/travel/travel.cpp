#include <iostream>
using namespace std;

int abs(int x) {
    return (x < 0) ? -x : x;
}

int charge(char c) {
    return c - 'A';
}

bool same_side(char a, char b) {
    return !((charge(a) < 3) ^ (charge(b) < 3));
}

signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2, x1, x2;
    char a, b;
    cin >> c1 >> x1 >> a >> c2 >> x2 >> b;
    cout << (c1 == c2);
    cout << ((c1 == c2) && (x1 == x2));
    cout << ((c1 == c2) && (x1 == x2) && same_side(a, b));
    cout << ((c1 == c2) && (x1 == x2) && same_side(a, b) && (abs(charge(a) - charge(b)) == 1));

}
