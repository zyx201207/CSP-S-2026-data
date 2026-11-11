#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x_room,x_num,r_room,r_num;
    cin >> x_room >> x_num >> r_room >> r_num;
    if(x_room == r_room){
        cout << 1;
        if(x_num.substr(0,2) == r_num.substr(0,2)){
            cout << 1;
            if((x_num[2] <='C' && r_num[2] <= 'C' )||(x_num[2] >'C' && r_num[2] > 'C' )){
                cout << 1;
                if(abs(x_num[2] - r_num[2]) == 1){
                    cout << 1;
                }else{
                    cout << "0";
                    return 0;
                }
            }else{
                cout << "00";
                return 0;
            }
        }else{
            cout << "000";
            return 0;
        }
    }else{
        cout << "0000";
        return 0;
    }
    return 0;
}
