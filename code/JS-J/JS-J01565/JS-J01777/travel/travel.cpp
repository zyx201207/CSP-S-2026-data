#include <bits/stdc++.h>
using namespace std;

int fff(int n) {
    return (n >= 0 ? n : (-n));
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << "1";
        string aa = s1.substr(0, 2), bb = s2.substr(0, 2);
        if (aa == bb) {
            cout << "1";
            int aaa = s1[2], bbb = s2[2];
            if (('A' <= aaa && aaa <= 'C' && 'A' <= bbb && bbb <= 'C') || ('D' <= aaa && aaa <= 'F' && 'D' <= bbb && bbb <= 'F')) {
                cout << "1";
                if ('A' <= aaa && aaa <= 'C' && 'A' <= bbb && bbb <= 'C') {
                    if (fff(aaa - bbb) == 1) {
                        cout << "1";
                    } else {
                        cout << "0";
                    }
                } else {
                    cout << "1";
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
