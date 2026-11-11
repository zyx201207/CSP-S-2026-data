#include <bits/stdc++.h>
using namespace std;

signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string s1, c1, s2, c2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2){
        cout << "0000\n";
    }
    else{
        cout << 1;
        string a1 = s1.substr(0, 2), a2 = s2.substr(0, 2);
        char b1 = s1[2], b2 = s2[2];
        if (a1 != a2){
            cout << "000\n";
        }
        else{
            cout << 1;
            if ((b1 >= 'A' && b1 <= 'C' && b2 >= 'D' && b2 <= 'F') || (b2 >= 'A' && b2 <= 'C' && b1 >= 'D' && b1 <= 'F')){
                cout << "00\n";
            }
            else{
                cout << 1;
                cout << int(b1 + 1 == b2 || b2 + 1 == b1) << "\n";
            }
        }
    }
    return 0;
}
