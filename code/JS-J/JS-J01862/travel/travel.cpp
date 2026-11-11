#include<bits/stdc++.h>
using namespace std;
using namespace std;
#define int long long
int c11, c22;
char s11[9], s22[9];
signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c11 >> s11 >> c22 >> s22;
    if (c11 == c22){
        cout << 1;
        int l11, l22;
        l11 = (s11[0] - '0') * 10 + (s11[1] - '0');
        l22 = (s22[0] - '0') * 10 + (s22[1] - '0');
        if (l11 == l22){
            cout << 1;
            if ((s11[2] <= 'C' && s22[2] <= 'C') || (s11[2] > 'C' && s22[2] > 'C')){
                cout << 1;
                //cout << s11 - s22 << endl;
                if ((s11[2] - s22[2] == 1) || (s22[2] - s11[2] == 1)){
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
            else{
                cout << "00";
            }
        }
        else{
            cout << "000";
        }
    }
    else{
        cout << "0000";
    }
    return 0;
}
