#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;string s3,s4;
    cin >> s1 >> s3;

    cin >> s2 >> s4;
    if(s1[0] == s2[0] && s1[1] == s2[1]) {
        cout << 1;
        if(s3[0] == s4[0] && s3[1] == s4[1]) {
            cout << 1;
            if((s3[2] <= 'C' && s4[2] <= 'C') || (s3[2] > 'C' && s4[2] > 'C')) {
                cout << 1;
                if(abs((int)(s3[2] - s4[2])) == 1) {
                    cout << 1;
                } else cout << 0;
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
    return 0;
}

/*
02 01A 02 01B
*/
