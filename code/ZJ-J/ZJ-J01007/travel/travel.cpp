#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c) {
        cout << 1;
        if (b[0] == d[0] && b[1] == d[1]) {
            cout << 1;
            if ((b[2] == 'A' || b[2] == 'B' || b[2] == 'C')) {
                if ((d[2] == 'A' || d[2] == 'B' || d[2] == 'C')) {
                    cout << 1;
                    if (abs((b[2] - 'A') - (d[2] - 'A')) == 1) cout << 1 << '\n';
                    else cout << 0 << '\n';
                }
                else cout << "00" << '\n';
            }
            else {
                if (d[2] == 'F' || d[2] == 'D') {
                    cout << 1;
                    if (abs((b[2] - 'A') - (d[2] - 'A')) == 2) cout << 1 << '\n';
                    else cout << 0 << '\n';
                }
                else cout << "00" << '\n';
            }
        }
        else cout << "000" << '\n';
    }
    else cout << "0000" << '\n';
    return 0;
}