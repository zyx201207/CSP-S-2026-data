#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;

    bool flag3 = false;
    if (c1 == c2) {
        cout << 1;
        flag3 = true;
    } else {
        cout << 0;
    }

    bool flag2 = false;

    if (flag3 && (s1[0] == s2[0] && s1[1] == s2[1])) {
        cout << 1;
        flag2 = true;
    } else {
        cout << 0;
    }

    bool flag = false;

    if (flag2 && ((s1[2] >= 'A' && s1[2] <= 'C' && 
        s2[2] >= 'A' && s2[2] <= 'C') || 
        (s1[2] >= 'D' && s1[2] <= 'F' && 
        s2[2] >= 'D' && s2[2] <= 'F') )) {
            cout << 1;
            flag = true;
    } else {
            cout << 0;
    }

    if (flag && (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1)) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}

/*n                                                                       
g++ travel.cpp -o travel -Wall -O2 -g 
time ./travel

*/
