#include<bits/stdc++.h>
using namespace std;
#define int long long
string a[104];
signed main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string x;
    for (int i = 1; i <= 4; i ++) cin >> a[i];
    if (a[1] == a[3]) x = "1";
    else {
        x = "0000";
        cout << x;
        return 0;
    }
    if (a[2][0] == a[4][0] && a[2][1] == a[4][1]) x += "1";
    else {
        x += "000";
        cout << x;
        return 0;
    }
    if (a[2][2] >= 'A' && a[2][2] <= 'C' && a[4][2] >= 'A' && a[4][2] <= 'C') {
        x += "1";
        if (a[2][2] == 'B' || a[4][2] == 'B') x += "1";
        else x += "0";
    }
    else if (a[2][2] == 'D' && a[4][2] == 'F' || a[4][2] == 'D' && a[2][2] == 'F') x += "11";
    else x += "00";
    cout << x;
    return 0;
}
