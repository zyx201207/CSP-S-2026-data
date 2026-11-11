#ifndef TRAVEL_CPP_INCLUDED
#define TRAVEL_CPP_INCLUDED
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[1]==s2[1]){
            cout<<"1";
            if(s1[2]<='C'&&s2[2]<='C'){
                cout<<"1";
                if(s1[2]=='B'||s2[2]=='B') cout<<"1";
                else cout<<"0";
            }
            else if(s1[2]>'C'&&s2[2]>'C') cout<<"11";
            else cout<<"00";
        }else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
#endif // HI_CPP_INCLUDED
