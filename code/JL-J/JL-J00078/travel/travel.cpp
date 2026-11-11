#include<bits/stdc++.h>
using namespace std;

int main() {

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string ca, cb, c1, c2;
    string ans = "";
    cin >> ca >> cb >> c1 >> c2;


    if(ca == c1) {
        ans += '1';
    }else {
        ans = "0000";
        cout << ans;
        return 0;
    }

    if(cb[0] == c2[0] && cb[1] == c2[1]) ans += '1';
    else {ans = "1000";cout << ans;return 0;}
    if((cb[2] <= 'C' && c2[2] <= 'C') || (cb[2] >= 'D' && c2[2] >= 'D')) ans += '1';
    else {ans = "1100";cout << ans;return 0;};
    if(cb[2] + 1 == c2[2] || cb[2] - 1 == c2[2]) ans += '1';
    else ans += '0';

    cout << ans;

    return 0;
}
