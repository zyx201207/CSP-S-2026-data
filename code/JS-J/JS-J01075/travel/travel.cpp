#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a != c){
        cout << "0000";
        return 0;
    }
    else{
        cout << '1';
        string s = b.substr(0,2);
        string ss = d.substr(0,2);
        if(ss == s){
            cout << '1';
            char x = b[2],y = d[2];
            if(x == 'D' && y == 'F' || y == 'D' && x == 'F'){
                cout << "11";
            }
            else if(x == 'F' || x == 'D' || y == 'D' || y == 'F'){
                cout << "00";
            }
            else if(abs(x - y) == 1){
                cout << "11";
            }
            else {
                cout << "10";
            }
        }
        else {
            cout << "000";
        }
    }
    return 0;
}
