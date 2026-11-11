#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    char c0, c1, c10, c2, c3, c4, c5, c6, c7, c8, c9;

    cin >> c0 >> c1 >> c2 >> c3 >> c4 >> c5 >> c6 >> c7 >> c8 >> c9;

    if(c0 == c5 && c1 == c6){
        cout << 1;
        if(c2 == c7 && c3 == c8){
            cout << 1;
            if((c4 < 'D' && c9 < 'D') || (c4 > 'C' && c9 > 'C')){
                cout << 1;
                if(c4 == c9 + 1 || c9 == c4 + 1 || c9 == 'D' && c4 == 'F' || c9 == 'F' && c4 == 'D') cout << 1;
                else cout << 0;
            } else cout << "00";
        } else cout << "000";
    } else cout << "0000";

    return 0;
}
