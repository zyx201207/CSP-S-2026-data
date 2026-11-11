# include <bits/stdc++.h>
using namespace std;
int a1, b1;
string a, b;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a1 >> a >> b1 >> b;
    int a2 = (a[0] - '0') * 10 + (a[1] - '0');
    int b2 = (b[0] - '0') * 10 + (b[1] - '0');
    char type1 = a[2], type2 = b[2];
    if (a1 == b1){
        cout << '1';
        if (a2 == b2){
            cout << '1';
            int code1 = (a[2] - 'A'), code2 = (b[2] - 'A');
            if ((code1 <= 2 && code2 <= 2) || (code1 > 2 && code2 > 2)){
                cout << '1';
                if (abs(code1 - code2) == 1) cout << '1';
                else cout << '0';
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
