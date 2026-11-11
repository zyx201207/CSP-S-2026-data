#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;

string c1, s1, c2, s2;
int buc[256];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    buc['A'] = 1;
    buc['B'] = 1;
    buc['C'] = 1;
    buc['D'] = 0;
    buc['E'] = 0;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << "1";
    } else {
        cout << "0";
    }
    if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) {
        cout << "1";
    } else {
        cout << "0";
    }
    if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && buc[s1[2]] == buc[s2[2]]) {
        cout << "1";
    } else {
        cout << "0";
    }
    if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && buc[s1[2]] == buc[s2[2]] && abs(s1[2] - s2[2]) == 1) {
        cout << "1";
    } else {
        cout << "0";
    }
    cout << '\n';
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}