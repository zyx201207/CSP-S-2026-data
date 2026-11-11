#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c) {
        cout << "1";
        int p1 = 0, p2 = 0;
        int pos = 0;
        while ('0' <= b[pos] and b[pos] <= '9') p1 = p1 * 10 + b[pos] - '0', pos ++;
        pos = 0;
        while ('0' <= d[pos] and d[pos] <= '9') p2 = p2 * 10 + d[pos] - '0', pos ++;
        //cerr << p1 << ' ' << p2;
        if (p1 == p2) {
            cout << "1";
            int k1 = b[b.size()-1] - 'A' + 1, k2 = d[d.size()-1] - 'A' + 1;
            if ((k1 <= 3 and k2 <= 3) or (k1 >= 4 and k2 >= 4)){
                cout << "1";
                if (abs(k1-k2) == 1) cout << "1";
                else cout << "0";
            }
            else cout << "00";
        } else cout << "000";
    }
    else cout << "0000";
    cout << '\n';
    return 0;
}
