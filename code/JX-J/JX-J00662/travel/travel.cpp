#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int r,x;
    string r_seat,x_seat;
    cin>>r>>r_seat>>x>>x_seat;
    if(r==x && r_seat!=x_seat){
        if(r!=1 && r!=16 && x!=1 && x!=16)
            cout<<1;
        else
            cout<<0;
    }else{
        cout<<"0000";
        return 0;
    }
    if(r_seat[0]==x_seat[0] && r_seat[1]==x_seat[1])
    {
        cout<<1;
        if(r_seat[2]<='C' && x_seat[2]<='C'){
            cout<<1;
            if(r_seat[2]=='A' && x_seat[2]=='C')
                cout<<0;
            else if(r_seat[2]=='C' && x_seat[2]=='A')
                cout<<0;
            else
                cout<<1;

        }else if(r_seat[2]>='D' && x_seat[2]<='D'){
            cout<<"11";
        }else{
            cout<<"00";
        }
    }else{
        cout<<"000";
    }
    return 0;
}
