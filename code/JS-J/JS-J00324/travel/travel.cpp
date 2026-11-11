#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    int a1;
    cin >> a1;
    string a2;
    cin >> a2;
    int b1;
    cin >> b1;
    string b2;
    cin >> b2;
    if(a1 == b1){
        cout << 1;
        if(b2[0] == a2[0] && b2[1] == a2[1]){
            cout << 1;
            int a = a2[2] - 'A' + 1;
            int b = b2[2] - 'A' + 1;
            if((a <= 3 && b <= 3) || (a >= 4 && b >= 4)){
                cout << 1;
                if(abs(a-b) == 1){
                    cout << 1;
                }
                else{
                    cout << 0;
                    return 0;
                }
            }
            else{
                cout << "00";
                return 0;
            }
        }
        else{
            cout << "000";
            return 0;
        }
    }
    else{
        cout << "0000";
        return 0;
    }
    return 0;
}
