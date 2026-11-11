#include<bits/stdc++.h>
using namespace std;

int rc,xc;
string rl,xl;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> rc >> rl >> xc >> xl;
    if(rc == xc){
        cout << 1;
        if(rl[1] == xl[1] && rl[0] == xl[0]){
        cout << 1;
        if((rl[2] == 'A' || rl[2] == 'B' || rl[2] == 'C')&&(xl[2] == 'A' || xl[2] == 'B' || xl[2] == 'C')){
            cout << 1;
            if(rl[2]+1 == xl[2] || rl[2]-1 == xl[2]){
                cout << 1;
            }else{
                cout << 0;
            }
        }else if((rl[2] == 'D' || rl[2] == 'F')&&(xl[2] == 'D' || xl[2] == 'F')){
            cout << 11;
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
