#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1 != b1) {
        cout << "0000\n";
    } else {
        cout << "1";
        if(a2[0] != b2[0] || a2[1] != b2[1]) {
            cout << "000\n";
        } else {
            cout << "1";
            int cka = 2, ckb = 2;;
            char azw = a2[2], bzw = b2[2];
            if(azw == 'A' || azw == 'B' || azw == 'C') cka = 1;
            if(bzw == 'A' || bzw == 'B' || bzw == 'C') ckb = 1;
            if(cka != ckb) {
                cout << "00\n";
            } else {
                cout << "1";
                if(cka == 2) {
                    cout << "1\n";
                } else {
                    int dif = azw - bzw;
                    if(dif < 0) dif = -dif;
                    if(dif != 1) {
                        cout << "0\n";
                    } else {
                        cout << "1\n";
                    }
                }
            }
        }
    }

    return 0;
}
