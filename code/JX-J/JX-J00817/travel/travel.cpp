#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    if(a != c)cout << "0000";
    else{
        cout << 1;
        if(b[0] == d[0] && b[1] == d[1])cout << 1;
        else{
            cout << "000";
            return 0;
        }
        if('A' <= b[2] && b[2] <= 'C' && 'A' <= d[2] && d[2] <= 'C'){
            cout << 1;
        }else if((b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D')){
            cout << 11;
            return 0;
        }else{
            cout << "00";
            return 0;
        }
        if(abs(b[2] - d[2]) == 1){
            cout << 1;
        }else cout << 0;
    }
}
