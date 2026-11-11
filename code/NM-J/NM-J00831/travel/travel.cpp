#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool p = false;
    int cx1,cx2;
    string zw1,zw2;
    cin >> cx1 >> zw1 >> cx2 >> zw2;
    if(cx1 == cx2) cout << '1';
    else{
        cout << '0';
        p = true;
    }
    if(p == true) cout << '0';
    else{
        if(zw1[0] == zw2[0] && zw1[1] == zw2[1]) cout << '1';
        else{
            cout << '0';
            p = true;
        }
    }
    if(p == true) cout << '0';
    else{
        if(zw1[2] == 'B' && zw2[2] == 'A'||zw1[2] == 'A' && zw2[2] == 'B'||zw1[2] == 'A' && zw2[2] == 'C'||zw1[2] == 'B' && zw2[2] == 'C'||zw1[2] == 'C' && zw2[2] == 'A'||zw1[2] == 'C' && zw2[2] == 'B'||zw1[2] == 'D' && zw2[2] == 'F'||zw1[2] == 'F' && zw2[2] == 'D') cout << '1';
        else cout << '0';
    }
    if(p == true) cout << '0';
    else{
        if(zw1[2] == 'B' && zw2[2] == 'A'||zw1[2] == 'A' && zw2[2] == 'B'||zw1[2] == 'B' && zw2[2] == 'C'||zw1[2] == 'C' && zw2[2] == 'B'||zw1[2] == 'D' && zw2[2] == 'F'||zw1[2] == 'F' && zw2[2] == 'D') cout << '1';
        else cout << '0';
    }
    return 0;
}