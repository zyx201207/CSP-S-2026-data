#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    char s11 = s1[0], s12 = s1[1], s13 = s1[2];
    char s21 = s2[0], s22 = s2[1], s23 = s2[2];
    if (c1 == c2) {
        cout << 1;
    }else {
        cout << "0000";
        return 0;
    }
    if (s11 == s21 && s12 == s22) {
        cout << 1;
    }else {
        cout << "000";
        return 0;
    }
    if (((s13 == 'A' || s13 == 'B' || s13 == 'C') && (s23 == 'A' || s23 == 'B' || s23 == 'C')) || ((s13 == 'D' || s13 == 'F') && (s23 == 'D' || s23 == 'F'))) {
        cout << 1;
    }else {
        cout << "00";
        return 0;
    }
    if (s13 == 'A' && s23 == 'B') {
        cout << 1;
    }else if (s13 == 'B' && s23 == 'C') {
        cout << 1;
    }else if (s13 == 'B' && s23 == 'A') {
        cout << 1;
    }else if (s13 == 'B' && s23 == 'C') {
        cout << 1;
    }else if (s13 == 'D' && s23 == 'F') {
        cout << 1;
    }else if (s23 == 'D' && s13 == 'F') {
        cout << 1;
    }else {
        cout << 0;
    }
    return 0;
}
