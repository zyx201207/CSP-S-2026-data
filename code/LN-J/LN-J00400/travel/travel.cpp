#include <bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> c >> b >> d;
    if(a == b) cout << "1";
    else {cout << "0000";return 0;}
    if(c[0] == d[0] && c[1] == d[1]) cout << "1";
    else {cout << "000";return 0;}
    if((('A' <= c[2] && c[2] <= 'C') && ('A' <= d[2] && d[2] <= 'C')) || ('D' <= c[2] && c[2] <= 'E' && ('D' <= d[2] && d[2] <= 'E'))) cout << "1";
    else {cout << "00";return 0;}
    if(abs(c[2]-d[2]) <= 1 && !(c[2] == 'C' && d[2] == 'D')) cout << "1";
    else cout << "0";
    cout << "/n";
    return 0;
}
//I want CSP-S 200+  thank the best CCF
