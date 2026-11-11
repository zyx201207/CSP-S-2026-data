#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string numr,numx;
    string seatr,seatx;
    cin>>numr>>seatr>>numx>>seatx;

    if(numr==numx){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }


    if(seatr[0]==seatx[0] && seatr[1]==seatx[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }


    if(seatr[2]<='C'&&seatx[2]<='C'){
        cout<<1;
        if(seatr[2]-'A'==seatx[2]-'A'+1 || seatr[2]-'A'==seatx[2]-'A'-1){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else if(seatr[2]>='D'&&seatr[2]<='E' && seatx[2]>='D'&&seatx[2]<='E'){
        cout<<11;
        return 0;
    }
    else{
        cout<<"00";
        return 0;
    }
    return 0;
}
