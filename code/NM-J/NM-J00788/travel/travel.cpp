#include<bits/stdc++.h>

using namespace std;

int at,bt;
string an,bn;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> at >> an >> bt >> bn;
    if(at == bt){
        cout << 1;
        if(an[0] == bn[0] && an[1] == bn[1]){
            cout << 1;
            if(!(an[2] >= 'D') ^ (bn[2] >= 'D')){
                cout << 1;
                if(abs(an[2]-bn[2]) == 1 && an[2] != 'C' && bn[2] != 'C'){
                    cout << 1;
                }else{
                    cout << "0";
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