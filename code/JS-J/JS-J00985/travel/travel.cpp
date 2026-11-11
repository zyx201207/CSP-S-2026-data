// Nina Iseri i love you

#include <bits/stdc++.h>
using namespace std;


#define range(v, l, r) next(begin(v), l), next(begin(x), r+1)
#define range_full(v) begin(v), end(v)


int64_t c1, c2;
string s1, s2; 
string p1, p2;
char l1, l2;


int32_t main() {
    ignore = freopen("travel.in", "r", stdin);
    ignore = freopen("travel.out", "w", stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {
        cout << "0000";
        return 0;
    }
    cout << 1;

    p1 = s1.substr(0, 2);
    p2 = s2.substr(0, 2);
    if (p1 != p2) {
        cout << "000";
        return 0;
    }
    cout << 1;

    l1 = s1[2];
    l2 = s2[2];
    if (l1 == 'A') {
        if (l2 == 'B') {
            cout << 11;
        }
        else if (l2 == 'C') {
            cout << 10;
        }
        else {
            cout << "00";
        }
    }
    if (l1 == 'B') {
        if (l2 == 'A') {
            cout << 11;
        }
        else if (l2 == 'C') {
            cout << 11;
        }
        else {
            cout << "00";
        }
    }
    if (l1 == 'C') {
        if (l2 == 'B') {
            cout << 11;
        }
        else if (l2 == 'A') {
            cout << 10;
        }
        else {
            cout << "00";
        }
    }
    if (l1 == 'D') {
        if (l2 == 'F') {
            cout << 11;
        }
        else {
            cout << "00";
        }
    }
    if (l1 == 'F') {
        if (l2 == 'D') {
            cout << 11;
        }
        else {
            cout << "00";
        }
    }



    return 0;
}