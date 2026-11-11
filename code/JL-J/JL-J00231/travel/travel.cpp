#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
    }else if(c1==c2&&s1==s2&&(s2!="01D"||s2!="02D"||s2!="03D"||s2!="04D"||s2!="05D"||s2!="06D"||s2!="07D"||s2!="08D"||s2!="09D"||s2!="10D"||s2!="11D"||s2!="12D"||s2!="13D"||s2!="14D"||s2!="15D"||s2!="16D"||s2!="17D"||s2!="18D")){
        cout<<"1111";
    }else if(s1+'1'==s2){
        cout<<"1110";
    }else if(s1=="01C"||s1=="02C"||s1=="03C"||s1=="04C"||s1=="05C"||s1=="06C"||s1=="07C"||s1=="08C"||s1=="09C"||s1=="10C"||s1=="11C"||s1=="12C"||s1=="13C"||s1=="14C"||s1=="15C"||s1=="16C"||s1=="17C"||s1=="18C"){
        cout<<"1100";
    }else{
        cout<<"1000";
    }
    return 0;
}
