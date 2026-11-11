#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int xc,xseat,rc,rseat;
    char xp,rp;
    cin >> xc >> xseat >> xp >> rc >> rseat >> rp;
    if (xc != rc ){
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    else cout << 1;
    if (xseat != rseat){
        cout << 0 << 0 << 0;
        return 0;
    }
    else cout << 1;
    if (int (xp) < 68 && int(rp) < 68){
        cout << 1;
        if (int(xp) +1 == int(rp) || int(rp) +1 == int (xp)){
            cout << 1;
        }
        else cout << 0;

    }
    else if (int (xp) > 67 || int(rp) <68){
        cout << 0 << 0;
    }
    else if(int (xp) < 68 || int(rp) > 67){
        cout << 0 << 0;
    }
    else cout << 1 << 1;
    return 0;

}

