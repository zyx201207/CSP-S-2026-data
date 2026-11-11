#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
signed main() {
    freopen("travel.in", "a+", stdin);
    freopen("travel.out", "w+", stdout);
    map<char, set<char>> can;
    can['A'] = set<char>{'B'};
    can['B'] = set<char>{'A', 'C'};
    can['C'] = set<char>{'B'};
    can['D'] = set<char>{'E'};
    can['E'] = set<char>{'D'};
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << "1";
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            cout << "1";

            if ((s1[2] <= 'C') == (s2[2] <= 'C')) {
                cout << "1";
                if (can[s1[2]].count(s2[2])) {
                    cout << "1";
                } else {
                    cout << "0";
                }
            } else {
                cout << "00";
            }

        }
        else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
}