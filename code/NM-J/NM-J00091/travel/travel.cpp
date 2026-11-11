#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    string s;
    int c1 , c2 ,s1, s2;
    cin >> c1 >> c2;
    cin >> s1 >> s2;
    if (c1 = c2 && c1 != 1 && c1 != 16 && c2 != 1 && c2 !=16){
        cout << 1;
    }
    else {
        c1 != c2;
        cout << 0;
    }


    if (s1=s2+1){
        cout << 1 ;
    }
    else {
        cout << 0;
    }
    int A,B ,C,D,F;
    if (s1=s2 && A=B || B=C || D=F){
        cout << 1;
    }
    else {
        cout << 0;
    }
    cout << 1111;
    return 0 ;


}
