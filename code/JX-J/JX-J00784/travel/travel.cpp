#include <bits/stdc++.h>
using namespace std;

int getside(char c) {
    if (c == 'A' || c == 'B' || c == 'C') return 0;
    return 1;
}

int getid(char c) {
    switch (c) {
        case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        case 'D': return 5;
        case 'F': return 6;
        default : return 0;
    }
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {
        cout << "0000";
        return 0;
    }
    if (s1[0] != s2[0] || s1[1] != s2[1]) {
        cout << "1000";
        return 0;
    }
    if (getside(s1[2]) != getside(s2[2])) {
        cout << "1100";
        return 0;
    }
    if (abs(getid(s1[2])-getid(s2[2])) != 1) {
        cout << "1110";
        return 0;
    }
    cout << "1111";
    return 0;
}