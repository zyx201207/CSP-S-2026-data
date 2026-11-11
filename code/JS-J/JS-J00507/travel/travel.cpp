#include <bits/stdc++.h>
using namespace std;
#define int long long
string case1, id1, case2, id2;
signed main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    cin >> case1 >> id1 >> case2 >> id2;
    int pos1 = stoll (case1);
    int pos2 = stoll (case2);
    char c1 = id1.back();
    id1.pop_back();
    char c2 = id2.back();
    id2.pop_back ();
    int d1 = stoll (id1), d2 = stoll (id2);
    if (pos1 == pos2) {
        cout << 1;
        if (d1 == d2) {
            cout << 1;
            if (c1 == 'F') {
                if (c2 == 'D')
                    cout << "11";
                else
                    cout << "00";
            }
            else if (c1 == 'D') {
                if (c2 == 'F')
                    cout << "11";
                else
                    cout << "00";
            }
            else {
                if (c2 == 'A' || c2 == 'B' || c2 == 'C') {
                    cout << 1;
                    if (c1 == 'A' && c2 == 'C')
                        cout << 0;
                    else if (c1 == 'C'&& c2 == 'A')
                        cout << 0;
                    else
                        cout << 1;
                }
                else
                    cout << "00";
            }
        }
        else
            cout << "000";
    }
    else {
        cout << "0000";
    }
    cout << '\n';
    return 0;
}
