#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int h1, h2, l1, l2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    h1 = (s1[0] - 48) * 10 + s1[1] - 48;
    h2 = (s2[0] - 48) * 10 + s2[1] - 48;
    l1 = s1[2] - 'A' + 1;
    l2 = s2[2] - 'A' + 1;
    if (c1 == c2) {
        cout << 1;
        if (h1 == h2){
            cout << 1;
            if ((l1 < 4 && l2 < 4) || (l1 > 3 && l2 > 3)){
                cout << 1;
                if (l1 - l2 == 1 || l2 - l1 == 1)
                    cout << 1;
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
