#include <bits/stdc++.h>

using namespace std;

int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << "1";
    }
    else {
        cout << "0";
    }
    string a, b;
    for (int i = 0; i < s1.size() - 1; i++) {
        a += s1[i];
    }
    for (int i = 0; i < s2.size() - 1; i++) {
        b += s2[i];
    }
    if (a == b) {
        cout << "1";
        if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) {
            cout << "1";
        }
        else if ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) {
            cout << "1";
        }
        else {
            cout << "0";
        }
        if (s1[2] == 'A' && s2[2] == 'B') {
            cout << "1";
        }
        else if (s1[2] == 'B' && (s2[2] == 'B' || s2[2] == 'C')) {
            cout << "1";
        }
        else if (s1[2] == 'C' && s2[2] == 'B') {
            cout << "1";
        }
        else if (s1[2] == 'D' && s2[2] == 'F') {
            cout << "1";
        }
        else if (s1[2] == 'F' && s2[2] == 'D') {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }
    else {
        cout << "000";
    }
    return 0;
}
