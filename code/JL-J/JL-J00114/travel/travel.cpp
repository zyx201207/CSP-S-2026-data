#include<bits/stdc++.h>
using namespace std;
long long rc,xc;
string rs,xs;
bool a=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> rc >> rs >> xc >> xs;

    if(rc==xc){
        cout << 1;
    }else{
        cout << 0;
        a=0;
    }

    string trs,txs;
    trs=rs[0]+rs[1];
    txs=xs[0]+xs[1];
    if(a!=0){
        if(trs==txs){
            cout << 1;
        }else{
            cout << 0;
            a=0;
        }
    }else{
        cout << 0;
    }


    string rst,xst;
    rst=rs[2];
    xst=xs[2];
    if(a!=0){
        if((rst=="A"&&xst=="B")||(rst=="A"&&xst=="C")||(rst=="B"&&xst=="A")||(rst=="C"&&xst=="A")||(rst=="B"&&xst=="C")||(rst=="C"&&xst=="B")||(rst=="D"&&xst=="F")||(rst=="F"&&xst=="D")){
            cout << 1;
        }else{
            cout << 0;
            a=0;
        }
    }else{
        cout << 0;
    }

    if(a!=0){
        if((rst=="A"&&xst=="B")||(rst=="B"&&xst=="A")||(rst=="B"&&xst=="C")||(rst=="C"&&xst=="B")||(rst=="D"&&xst=="F")||(rst=="F"&&xst=="D")){
            cout << 1;
        }else{
            cout << 0;
        }
    }else{
        cout << 0;
    }

    return 0;
}
