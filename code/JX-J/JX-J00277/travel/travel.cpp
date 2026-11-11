#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c, s, p, q;
    cin >> c >> s >> p >> q;
    if(c != p){
        cout << "0000";
        return 0;
    }
    else {
        cout << 1;
        if(s[0] != q[0] || s[1] != q[1]) {
            cout << "000";
            return 0;
        }
        else {
            cout << 1;
            if(((s[2] == 'A' || s[2] == 'B' || s[2] == 'C') && (q[2] == 'D' || q[2] == 'E')) || ((q[2] == 'A' || q[2] == 'B' || q[2] == 'C') && (s[2] == 'D' || s[2] == 'E'))) {
                cout << "00";
                return 0;
            }
            else {
                cout << 1;
                if((s[2] == 'A' && q[2] != 'B') || (s[2] == 'C' && q[2] != 'B')) {
                    cout << 0;
                }
                else cout << 1;
            }
        }
    }
    return 0;
}
