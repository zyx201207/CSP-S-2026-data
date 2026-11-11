#include <bits/stdc++.h>

using namespace std;

#define int long long



inline int check(char a) {
    if (a == 'A' || a == 'B' || a == 'C') {
        return 1;
    }else {
        return 2;
    }
}

inline bool check2(string &s11, string &s22) {
    char a = s11[2], b = s22[2];
    if ((a == 'C' && b == 'B') || (a == 'B' && b == 'C')) {
        return true;
    }else if ((a == 'D' && b == 'E') || (a == 'E' && b == 'D')) {
        return true;
    }else if ((a - 1 == b || b - 1 == a) && a != 'C' && a != 'D') {
        return true;
    }
    return false;
}


inline void solve(){
    string str = "";
    string s1, s2, y1, y2;
    cin >> s1 >> s2 >> y1 >> y2;
    // 判断 1
    if (s1 == y1) {
        str += '1';
    }else {
        cout << "0000" << '\n';
        return;
    }

    if (s2[0] == y2[0] && s2[1] == y2[1]) {
        str += '1';
    } 
    else {
        cout << "1000" << '\n';
        return;
    }

    if (check(s2[2]) == check(y2[2])){
        str += '1';
    } else {
        cout << "1100" << '\n';
        return;
    }

    if (check2(s2, y2)) {
        str += '1';
    } else {
        cout << "1110" << '\n';
        return;
    }
    cout << str << '\n';
    return;
}

signed main () {
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
    return 0;
    // CSP AK!!!
}
