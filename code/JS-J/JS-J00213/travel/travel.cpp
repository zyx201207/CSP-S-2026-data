#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;

    if(c1[1]+c1[0]*10==c2[1]+c2[0]*10)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }

    if(s1[0]*10+s1[1]==s2[0]*10+s2[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }

    if(s1[2]=='D'||s1[2]=='F'){
        if(s2[2]=='D'||s2[2]=='F'){
            cout<<11;
            return 0;
        }
        else{
            cout<<"00";
            return 0;
        }
    }else if(s2[2]=='D'||s2[2]=='F'){
        cout<<"00";
        return 0;
    }else{
        cout<<1;
    }

    if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
        cout<<1;
    }else cout<<0;
}









//g++ -std=c++14 -Wall -Wextra -o XXX XXX.cpp
//./XXX
//diff XXX.out XXX.ans
