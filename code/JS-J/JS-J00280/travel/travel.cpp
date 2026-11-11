#include <bits/stdc++.h>
using namespace std;
string co,so,ct,st;
bool check(){
    if ((so[2] == 'A' && (st[2] == 'B' || st[2] == 'C')) || (so[2] == 'B' && (st[2] == 'A' || st[2] == 'C')) || (so[2] == 'C' && (st[2] == 'A' || st[2] == 'B')) || (so[2] == 'D' && st[2] == 'F') || (so[2] == 'F' && st[2] == 'D')){
        return 1;
    }
    return 0;
}
bool xcheck(){
    if ((so[2] == 'A' && st[2] == 'B') || (so[2] == 'B' && (st[2] == 'A' || st[2] == 'C')) || (so[2] == 'C' && st[2] == 'B') || (so[2] == 'D' && st[2] == 'F') || (so[2] == 'F' && st[2] == 'D')){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> co >> so >> ct >> st;
    if (co == ct){
        cout << "1";
        if (so[0] + so[1] == st[0] + st[1]){
            cout << "1";
            if (check()){
                cout << "1";
                if (xcheck()){
                    cout << "1";
                }
                else {
                    cout << "0";
                }
            }
            else {
                cout << "00";
            }
        }
        else {
            cout << "000";
        }
    }
    else {
        cout << "0000";
    }
    return 0;
}
