#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

void solve1() {
    if (c1 == c2) {
        cout << 1;
    } else {
        cout << 0;
    }
}

void solve2() {
    if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) {
        cout << 1;
    } else {
        cout << 0;
    }
}

int lorr(char a) {
    if (a == 'A' || a == 'B' || a == 'C') {
        return 1;
    } else {
        return 2;
    }
}

void solve3() {
    char x = s1[2], y = s2[2];
    if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && lorr(x) == lorr(y)) {
        cout << 1;
    } else {
        cout << 0;
    }
}

void solve4() {
    char x = s1[2], y = s2[2];
    if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && lorr(x) == lorr(y) && abs(x - y) == 1) {
        cout << 1;
    } else {
        cout << 0;
    }
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    solve1();
    solve2();
    solve3();
    solve4();
    return 0;
}
