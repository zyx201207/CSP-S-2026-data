#include <bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx,r_="0000";

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cr>>sr>>cx>>sx;
    if(cr==cx){
        r_[0]='1';
    }else{
        r_[0]='0';
    }
    if(sr[0]==sx[0]&&sr[1]==sx[1]&&r_[1]=='1'){
        r_[1]='1';
    }else{
        r_[1]='0';
    }
    if(r_[1]=='1'){
        if(sr[2]=='F'||sr[2]=='D'&(sx[2]=='F'||sx[2]=='D')){
            r_[2]='1';
    }else {
        r_[2]='0';
    }
    }else{
        r_[2]='0';
    }
    if(r_[1]=='1'&&(sr[2]=='F'||sr[2]=='D'||sr[2]=='B'||sx[2]=='B')){
        r_[3]='1';
    }else{
        r_[3]='0';
    }
    cout<<r_;
    return 0;
}

