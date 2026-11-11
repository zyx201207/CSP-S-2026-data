#include<bits/stdc++.h>
using namespace std;
int cr,cx;
char sr[3],sx[3];
bool scr,sl,sss,sid;
bool same_side(){
    if('A'<=sr[2]<='C'){
        if('A'<=sx[2]<='C'){
            return true;
        }
        return false;
    }
    else if('D'<=sr[2]<='F'){
        if('D'<=sx[2]<='F'){
            return true;
        }
        return false;
    }
}
bool is_nxt(){
    if('A'<=sr[2]<='C'){
        if(sr[2]=='A'){
            if(sx[2]=='B') return true;
            return false;
        }
        else if(sr[2]=='B'){
            if(sx[2]=='A'||sx[2]=='C') return true;
            return false;
        }
        else{
            if(sx[2]=='B') return true;
            return false;
        }
    }
    else{
        if('D'<=sx[2]<='F') return true;
        return false;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cr>>sr>>cx>>sx;
    if(cr==cx) scr=1;
    if(scr&&(sr[0]==sx[0]&&sr[1]==sx[1])) sl=1;
    if(scr&&sl&&same_side()) sss=1;
    if(scr&&sl&&sss&&is_nxt()) sid=1;
    cout<<scr<<sl<<sss<<sid;
    return 0;
}
