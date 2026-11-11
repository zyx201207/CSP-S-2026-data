#include <bits/stdc++.h>
using namespace std;
int main() {
    fstream cin("travel.in");
    ofstream cout("travel.out");
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
    cout << 1;
    if (s1.substr(0, 2) == s2.substr(0, 2)) {
        cout << 1;
        if (s1[2] <= 'C' && s2[2] <= 'C') {
            cout << 1;
            cout << (abs(s1[2]-s2[2])==1);
        }
        else if (s1[2] >= 'D' && s1[2] >= 'D')
            cout << "11";
        else cout << "00";
    }
    else cout << "000";
    }
    else cout << "0000";
    return 0;
}
