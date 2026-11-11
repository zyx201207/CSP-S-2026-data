#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int rr, rx;
string lr, lx;

bool instr(char c1, char c2, string s) {
    bool b1 = 0, b2 = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == c1) b1 = 1;
        if (s[i] == c2) b2 = 1;
    }
    return (b1 && b2);
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> rr >> lr >> rx >> lx;

    bool p1 = (rr == rx);
    bool p2 = (p1 && lr[0] == lx[0] && lr[1] == lx[1]);
    bool p3 = (p2 && (instr(lr[2], lx[2], "ABC") || instr(lr[2], lx[2], "DF")));
    bool p4 = (p2 && (lr[2] == 'A' && lx[2] == 'B'
                      || lr[2] == 'B' && (lx[2] == 'A' || lx[2] == 'C')
                      || lr[2] == 'C' && lx[2] == 'B'
                      || instr(lr[2], lx[2], "DF")));

    cout << p1 << p2 << p3 << p4;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
