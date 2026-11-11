#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
string s1, s2;
string c1, c2;

string col(string t) {
    int i = 0;
    string ans = "";

    while (!isalpha(t[i])) {
        ans += t[i]; i++;
    }

    return ans;
}

bool sid(string a, string b) {
    char e = a[2], f = b[2];
    if (e == 'A' || e == 'B' || e == 'C') {
        if (f == 'A' || f == 'B' || f == 'C') {
            return true;
        }
    } else {
        if (f == 'D' || f == 'F') {
            return true;
        }
    }
    return false;

}

bool bs(string p, string q) {
    char x = p[2], y = q[2];
    if (x == 'A' || x == 'C') {
        if (y == 'B') {
            return true;
        }
    } else if (x == 'B') {
        if (y == 'A' || y == 'C') {
            return true;
        }
    } else if (x == 'D') {
        if (y == 'F') {
            return true;
        }
    } else if (x == 'F') {
        if (y == 'D') {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << 1;
        if (col(s1) == col(s2)) {
            cout << 1;
            if (sid(s1, s2)) {
                cout << 1;
                if (bs(s1, s2)) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
    return 0;
}
