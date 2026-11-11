#include <bits/stdc++.h>
using namespace std;
string a, b, a1, b1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> a1 >> b >> b1;
    if (a != b) {
        cout << "0000" << endl;
        return 0;
    }
    else {
        cout << "1";
        if (a1[0] != b1[0] || a1[1] != b1[1]) cout << "000";
        else {
            cout << "1";
            int m = (int)(a1[2]), n = (int)(b1[2]);
            if ((m == 65 || m == 66 || m == 67) && (n == 65 || n == 66 || n == 67)) {
                cout << "1";
                if (m + 1 == n || m - 1 == n) {
                    cout << "1";
                    return 0;
                }
                else {
                    cout << "0";
                    return 0;
                }
            }
            else if ((m == 68 || m == 70) && (n == 68 || n == 70)) {
                cout << "11";
                return 0;
            }
            else cout << "00";
        }
    }
    return 0;
}
