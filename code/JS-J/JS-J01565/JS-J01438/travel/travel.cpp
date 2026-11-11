#include <bits/stdc++.h>
using namespace std;

bool check(char w1, char w2) {
    if ('A' <= w1 && w1 <= 'C' && 'A' <= w2 && w2 <= 'C') {
        return 1;
    }
    if ('D' <= w1 && w1 <= 'F' && 'D' <= w2 && w2 <= 'F') {
        return 1;
    }
    return 0;
}

bool check2(char w1, char w2) {
    if (w1 > w2) {
        swap(w1, w2);
    }
    if ('A' <= w1 && w1 <= 'C' && 'A' <= w2 && w2 <= 'C') {
        if (w1 + 1 == w2) {
            return 1;
        }
    }
    if ('D' <= w1 && w1 <= 'F' && 'D' <= w2 && w2 <= 'F') {
        if (w1 + 2 == w2) {
            return 1;
        }
    }
    return 0;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << 1;
    } else {
        cout << 0;
    }
    string p1 = s1.substr(0, 2), p2 = s2.substr(0, 2);
    if (c1 == c2 && p1 == p2) {
        cout << 1;
    } else {
        cout << 0;
    }
    char w1 = s1[2], w2 = s2[2];
    if (c1 == c2 && p1 == p2 && check(w1, w2)) {
        cout << 1;
    } else {
        cout << 0;
    }
    if (c1 == c2 && p1 == p2 && check(w1, w2) && check2(w1, w2)) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}
