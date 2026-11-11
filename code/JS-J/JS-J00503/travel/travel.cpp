#include <bits/stdc++.h>
#define ll long long
using namespace std;
string a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a1 >> a2 >> b1 >> b2;
    if (a1 == b1){
        cout << 1;
        if (a2[0] == a2[0] && a2[1] == a2[1]){
            cout << 1;
            char za = a2[2],zb = b2[2];
            int a = 0,b = 0;
            if (za == 'A'){
                a = 1;
            }
            else if (za == 'B'){
                a = 2;
            }
            else if (za == 'C'){
                a = 3;
            }
            else if (za == 'D'){
                a = 4;
            }
            else{
                a = 5;
            }
            if (zb == 'A'){
                b = 1;
            }
            else if (zb == 'B'){
                b = 2;
            }
            else if (zb == 'C'){
                b = 3;
            }
            else if (zb == 'D'){
                b = 4;
            }
            else{
                b = 5;
            }
            if (a > b){
                swap(a,b);
            }
            if ((a <= 3 && b <= 3) || (a >= 4 && b >= 4)){
                cout << 1;
                if (a + 1 == b){
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
            else {
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
    cout << a2[2] << b2[2];
}
