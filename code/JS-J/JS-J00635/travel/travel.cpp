#include <bits/stdc++.h>
using namespace std;
char a2[5], b2[5];
int a3, b3;
char a4, b4;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a1, b1;
    cin >> a1;
    for(int i = 0; i < 3; i ++) cin >> a2[i];
    cin >> b1;
    for(int i = 0; i < 3; i ++) cin >> b2[i];
    for(int i = 0; i < 2; i ++) a3 += a2[i] - '0';
    for(int i = 0; i < 2; i ++) b3 += b2[i] - '0';
    a4 = a2[2];
    b4 = b2[2];
    if(a1 == b1){
        cout << '1';
        if(a3 == b3){
            cout << '1';
            if(a4 <= 'C' && b4 <= 'C' || a4 >= 'D' && b4 >= 'D'){
                cout << '1';
                if(abs(a4 - b4) <= 1){
                    cout << '1';
                }else cout << '0';
            }else cout << "00";
        } else cout << "000";
    }else cout << "0000";
    return 0;
}
