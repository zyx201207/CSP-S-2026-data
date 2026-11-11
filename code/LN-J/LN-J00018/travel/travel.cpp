#include <bits/stdc++.h>
using namespace std;
int cr,cx;string sr,sx;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cr>>sr>>cx>>sx;
    if(cr==cx){
        cout<<"1";
    }
    else{
        cout<<"0000";return 0;
    }
    if(sr.substr(0,2)==sx.substr(0,2)){
        cout<<"1";
    }
    else{
        cout<<"000";return 0;
    }
    if(sr[2]<='C' && sx[2]<='C'){
        cout<<"1";
    }
    else if(sr[2]>'C' && sx[2]>'C'){
        cout<<"11";return 0;
    }
    else{
        cout<<"00";return 0;
    }
    if(sr[2]=='A' && sx[2]=='B'){
        cout<<"1";return 0;
    }
    if(sr[2]=='B' && sx[2]=='C'){
        cout<<"1";return 0;
    }
    if(sr[2]=='B' && sx[2]=='A'){
        cout<<"1";return 0;
    }
    if(sr[2]=='C' && sx[2]=='B'){
        cout<<"1";return 0;
    }
    cout<<"0";
    return 0;
}
