#include <bits/stdc++.h>
using namespace std;

int main(){
    //8:45:33 finish
    //10:53:41 first check(all tasks correct)
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == c) cout << 1;
    else{
        cout << "0000\n";
        return 0;
    }
    if(b[0] == d[0] && b[1] == d[1]) cout << 1;
    else{
        cout << "000\n";
        return 0;
    }
    if(((b[2] >= 'D' && d[2] >= 'D') || (b[2] <= 'C' && d[2] <= 'C'))){
        if(!(b[2] == 'A' && d[2] == 'C' || b[2] == 'C' && d[2] == 'A')) cout << "11\n";
        else cout << "10\n";
    }
    else cout << "00\n";
}
