#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a1, a2, b1, b2;
string x, y;
ll id1, id2, seat1, seat2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1 != b1) {
        cout << "0000";
        return 0;
    } else {
        cout << 1;
    }
    for(int i = 0;i < 2;++i) {
        x = x + a2[i];
        y = y + b2[i];
    }
    if(x != y) {
        cout << "000";
        return 0;
    } else {
        cout << 1;
    }
    if((a2[2] <= 'C' && b2[2] >= 'D') || (a2[2] >= 'D' && b2[2] <= 'C')) {
        cout << "00";
    } else {
        cout << 1;
        if((a2[2] == 'A' && b2[2] == 'C') || (a2[2] == 'C' && b2[2] == 'A')) {
            cout << 0;
        } else {
            cout << 1;
        }
    }
    return 0;
}
