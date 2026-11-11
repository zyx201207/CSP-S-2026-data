#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a;
    string b;
    string c;
    string d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    if(a == c){
        cout << 1;
        if(b[0] == d[0] && b[1] == d[1]){
            cout << 1;
            int f = b[2] - 'A';
            int g = d[2] - 'A';
            if((f >= 0 && f <= 2 && g >= 0 && g <= 2) || (f >= 3 && f <= 4 && g >= 3 && g <= 4)){
                cout << 1;
                if(abs(f-g) == 1){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else{
                cout << "00";
            }
        }else{
            cout << "000";
        }
    }else{
        cout << "0000";
    }
    return 0;
}
