#include <bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;

int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    int rc, xc, rs, xs;
    rc = (c1[0] - '0') * 10 + (c1[1] - '0');
    xc = (c2[0] - '0') * 10 + (c2[1] - '0');
    rs = (s1[0] - '0') * 10 + (s1[1] - '0');
    xs = (s2[0] - '0') * 10 + (s2[1] - '0');

    bool a, b, c;
    if(rc == xc) {
        cout << 1;
        a = 1;
    }else {
        cout << 0;
        a = 0;
    }

    if(a) {
        if(rs == xs) {
            cout << 1;
            b = 1;
        }else {
            cout << 0;
            b = 0;
        }
    }else {
        cout << 0;
        b = 0;
    }

    if(a && b) {
        if(s1[2] <= 'C' && s2[2] <= 'C' || s1[2] > 'C' && s2[2] > 'C') {
            cout << 1;
            c = 1;
        }else {
            cout << 0;
            c = 0;
        }
    }else {
        cout << 0;
        c = 0;
    }

    if(a && b && c) {
        if(s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1) cout << 1;
        else cout << 0;
    }
    else cout << 0;

    return 0;
}