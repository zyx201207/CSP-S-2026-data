#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>> a>>b>>c>>d;
    if(a==c)
        cout << 1;
    else {
        cout << "0000";
        return 0;}
    if(b[1]==d[1])
        cout << 1;
    else {
        cout << "000";
        return 0;}
    if(b[2]<='C'&&d[2]<='C')
        cout << 1;
    else if(b[2]<='E'&&d[2]<='E')
        cout << 1;
    else {
        cout << "00";
        return 0;}
    if(b[2]-d[2]==1||b[2]-d[2]==-1) cout << 1;
    else cout << "0";
    return 0;
}
