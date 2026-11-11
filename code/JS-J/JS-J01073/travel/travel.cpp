#include<bits/stdc++.h>
using namespace std;
#define int long long
int f1,f2,f3,f4;
bool check(char x,char y){
    bool rev=0;
    if(x=='D'||x=='F'){
        if(y=='D'||y=='F'){
            rev=1;
        }
    }else{
        if(y=='A'||y=='B'||y=='C'){
            rev=1;
        }
    }
    return rev;
}
bool check2(char x,char y){
    int rev=0;
    if(x=='A'&&y=='B'){
        rev=1;
    }
    if(x=='B'&&y=='C'){
        rev=1;
    }
    if(x=='D'&&y=='F'){
        rev=1;
    }
    return rev;
}
//02 01A 02 01B
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    string idx,idy,seatx,seaty;
    cin>>idx>>seatx>>idy>>seaty;
    if(idx==idy){
        f1=1;
        //rx lx ry ly
        char lx=seatx[2],ly=seaty[2];
//        cout<<lx<<ly;
        if(seatx[0]==seaty[0]&&seatx[1]==seaty[1]){
            f2=1;
            if(check(lx,ly)){
                f3=1;
                if(check2(lx,ly)||check2(ly,lx)){
                    f4=1;
                }
            }
        }
    }
    cout<<f1<<f2<<f3<<f4;

    return 0;
}
