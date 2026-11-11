#include <bits/stdc++.h>
using namespace std;

string s, s1, s2, s3, s4, s5;
char ch, ch1;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> s >> s1 >> s2 >> s3;
    if (s != s2) {
        cout << "0000" << endl;
        return 0;
    }
    s4 = s1.substr(0, 2);
    s5 = s3.substr(0, 2);
    if (s4 != s5) {
        cout << "1000" << endl;
        return 0;
    }
    ch = s1[2];
    ch1 = s3[2];
    if (ch >= 'D' && ch1 < 'D' || ch < 'D' && ch1 >= 'D') {
        cout << "1100" << endl;
        return 0;
    }
    if (abs(ch - ch1) != 1) {
        cout << "1110" << endl;
        return 0;
    }
    cout << "1111" << endl;
    return 0;
}