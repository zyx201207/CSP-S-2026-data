#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;

    cout << (c1 == c2);

    bool flag = ((c1 == c2) && (s1[0] == s2[0]) && (s1[1] == s2[1]));
    cout << flag;

    bool aaa = ((s1[2] == 'A' || s1[2] == 'c' || s1[2] == 'B') && (s2[2] == 'A' || s2[2] == 'c' || s2[2] == 'B'));
    bool bbb = ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'));

    if (flag && (aaa || bbb)) {

        cout << 1;

    }

    else {

        cout << 0;

    }

    if (flag && aaa && (((int)(s1[2] - '0') - 1 == (int)(s2[2] - '0')) || ((int)(s1[2] - '0') + 1 == (int)(s2[2] - '0')))) {

        cout << 1;

    }

    else if (flag && bbb && (((int)(s1[2] - '0') - 2 == (int)(s2[2] - '0')) || ((int)(s1[2] - '0') + 2 == (int)(s2[2] - '0')))) {

        cout << 1;

    }

    else {

        cout << 0;

    }


    return 0;
}
