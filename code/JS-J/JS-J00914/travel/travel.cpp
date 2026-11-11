#include<bits/stdc++.h>
#define FILENAME "travel"
using namespace std;

bool check(string s) {
    char c = s[0];
    return ('A' <= c && c <= 'C');
}

void solve() {
    string a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    if (a1 == b1) cout << 1;
    else {
        cout << "0000\n";
        return;
    }
    if (a2.substr(0, 2) == b2.substr(0, 2)) {
        cout << 1;
    }
    else {
        cout << "000\n";
        return;
    }
    if (check(a2.substr(2)) == check(b2.substr(2))) {
        cout << 1;
    }
    else {
        cout << "00\n";
        return;
    }
    if (abs(a2.substr(2)[0] - b2.substr(2)[0]) <= 1) {
        cout << 1;
    }
    else {
        cout << "0\n";
        return;
    }
    cout << '\n';
}

int main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}