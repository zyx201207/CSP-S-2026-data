#include <iostream>
using namespace std;
bool f1(char a, char b) {
    return (a <= 'C' && b <= 'C') || (a >= 'D' && b >= 'D');
}
bool f2(char a, char b) {
    if (a > b)
        swap(a, b);
    return (a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F');
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin.tie(nullptr);
    int a1, b1;
    string a2, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    if (!(a1 == b1)) {
        puts("0000");
        return 0;
    }
    cout << 1;
    if (!((a2[0] == b2[0]) && (a2[1] == b2[1]))) {
        puts("000");
        return 0;
    }
    cout << 1;
    if (!f1(a2[2], b2[2])) {
        puts("00");
        return 0;
    }
    cout << 1;
    cout << f2(a2[2], b2[2]);
    return 0;
}