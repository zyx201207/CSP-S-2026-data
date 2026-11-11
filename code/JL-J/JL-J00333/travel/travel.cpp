#include <bits/stdc++.h>
using namespace std;

string c1, c2, c3, c4;

void ab(char &a) {
    if (a >= 'A' && a <= 'C') {
        a = 'A';
    } else {
        a = 'D';
    }
}

void solve() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> c2 >> c3 >> c4;
    if (c1 == c3) {
        cout << 1;
    } else {
        cout << "0000";
        return;
    }
    if (c2.substr(0, 2) == c4.substr(0, 2)) {
        cout << 1;
    } else {
        cout << "000";
        return;
    }
    char a = c2[2], b = c4[2];
    ab(a);
    ab(b);
    if (a == b) {
        cout << 1;
    } else {
        cout << "00";
        return;
    }
    if (c2[2] + 1 == c4[2] || c2[2] - 1 == c4[2]) {
        cout << 1;
    } else {
        cout << 0;
        return;
    }
}

int main() {
    int ac = 1;
    // cin >> ac;
    while(ac--) {
        solve();
    }
}
