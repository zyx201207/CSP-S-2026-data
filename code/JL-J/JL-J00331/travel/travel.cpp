#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    int aa = 0;
    if(a[0] == c[0] && a[1] == c[1]) aa = 1;
    int bb = 0;
    if(b[0] == d[0] && b[1] == d[1]) bb = 1;
    int cc = 0;
    if((b[2] == 'A' || b[2] == 'B' || b[2] == 'C') && (d[2] == 'A' || d[2] == 'B' || d[2] == 'C')) cc = 1;
    else if((b[2] == 'D' || b[2] == 'F') && (d[2] == 'D' || d[2] == 'F')) cc = 1;
    int dd = 0;
    if((int) b[2] - (int) d[2] == 1 || (int) d[2] - (int) b[2] == 1) dd = 1;
    if(cc == 0){
        dd = 0;
    }
    if(bb == 0){
        cc = 0;
        dd = 0;
    }
    if(aa == 0){
        bb = 0;
        cc = 0;
        dd = 0;
    }
    cout << aa << bb << cc << dd;
    return 0;
}
