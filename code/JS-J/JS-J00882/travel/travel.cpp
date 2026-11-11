#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2, ans="";
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << "1";
    else {
        cout << "0000";
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1]) {
        cout << "1";
        char a = s1[2], b = s2[2];
        if(((a == 'A' || a == 'B' || a == 'C' )&& (b == 'A' || b == 'B' || b == 'C' )) || ((a == 'D' || a == 'E') && (b == 'D' || b == 'E'))  ) cout <<  "1";
        else {
            cout << "00";
            return 0;
        }
    }
    else {
        cout << "000";
        return 0;
    }
    int a = s1[2], b = s2[2];
    if ((a == 'A' && b == 'B') || (a == 'B' && b == 'A') || (a == 'B' && b == 'C') || (a == 'C' && b == 'B') || (a == 'D' && b == 'E') || (a == 'E' && b == 'D'))
        cout << "1";
    else cout << "0";
    return 0;
}
