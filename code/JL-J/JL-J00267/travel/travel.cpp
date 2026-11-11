

#include<bits/stdc++.h>
using namespace std;
struct Pasg{
    int cart;
    string seat;
}r, x;
string r2, x2;
char r3, x3;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> r.cart >> r.seat >> x.cart >> x.seat;
    if(r.cart == x.cart) cout << 1;
    else {cout << "0000"; return 0;}
    r2 = r.seat[0] + r.seat[1];
    x2 = x.seat[0] + x.seat[1];
    if(r2 == x2) cout << 1;
    else {cout << "000"; return 0;}
    r3 = r.seat[2];
    x3 = x.seat[2];
    bool flag = false;
    if(r3 == 'A' || r3 == 'B' || r3 == 'C'){
        if(x3 == 'A' || x3 == 'B' || x3 == 'C'){
            cout << 1;
            flag = true;
        }
        else{
            cout << "00";
            return 0;
        }
    }
    else{
        if(x3 == 'D' || x3 == 'F'){
            cout << 1;
            flag = true;
        }
        else{
            cout << "00";
            return 0;
        }
    }
    if(((r3 == x3 + 1) || (x3 == r3 + 1)) && flag) cout << 1;
    else cout << 0;
    cout << endl;
    //cout << '\n' << r3 << "|" << x3;
    return 0;
}

