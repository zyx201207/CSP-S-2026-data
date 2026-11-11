#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int zhuan(string s) {
    if (s[0] == '0') {
        return s[1] - '0';
    } else {
        return (s[0]-'0')*10 + (s[1] - '0');
    }
}

int zhuan2(string s) {
    return s[2]-'A';
}

bool check(int a, int b) {
    if (a <= 2 && b > 2) {
        return 0;
    }
    if (b <= 2 && a > 2) {
        return 0;
    }
    return 1;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string cr, sr, cx, sx;
    cin >> cr >> sr >> cx >> sx;
    int ar, ax;
    ar = zhuan(cr);
    ax = zhuan(cx);
    if (ar == ax) {
        cout << 1;
        if (zhuan(sr) == zhuan(sx)) {
            cout << 1;
            if (check(zhuan2(sr), zhuan2(sx))) {
                cout << 1;
                if (max(zhuan2(sr), zhuan2(sx))-min(zhuan2(sr), zhuan2(sx)) == 1) {
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
