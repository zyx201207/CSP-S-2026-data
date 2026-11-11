#include <bits/stdc++.h>
using namespace std;

string r1, r2, x1, x2;

signed main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> r1 >> r2 >> x1 >> x2;
    if (r1 == x1) cout << "1";
    else {
        cout << "0000";
        return 0;
    }
    if (r2[0] == x2[0] && r2[1] == x2[1]) cout << "1";
    else {
        cout << "000";
        return 0;
    }
    if ((r2[2] >= 'A' && r2[2] <= 'C' && x2[2] >= 'A' && x2[2] <= 'C') || (r2[2] >= 'D' && r2[2] <= 'F' && x2[2] >= 'D' && x2[2] <= 'F')) cout << "1";
    else {
        cout << "00";
        return 0;
    }
    if (abs(int(r2[2]) - int(x2[2])) == 1) cout << "1";
    else cout << "0";
    return 0;
}