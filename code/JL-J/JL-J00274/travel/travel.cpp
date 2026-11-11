#include<bits/stdc++.h>
using namespace std;
string s1,sw1,s2,sw2;
int c1,c2,w1,w2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>s1>>sw1>>s2>>sw2;
c1=(s1[0]-'0')*10+(s1[1]-'0');
c2=(s2[0]-'0')*10+(s2[1]-'0');
if(c1==c2){
    cout<<"1";
    s1=(sw1[0]-'0')*10+(sw1[1]-'0');
    s2=(sw2[0]-'0')*10+(sw2[1]-'0');
    if(s1==s2){
            cout<<"1";
        if((sw1[2]<='C' && sw2[2]<='C') || (sw1[2]>'C' && sw2[2]>'C')){
            cout<<"1";
            if(abs(sw1[2]-sw2[2])==1 || (sw1[2]>'C' && sw2[2]>'C')) cout<<"1";
            else cout<<"0";
        }
        else cout<<"00";
    }
    else cout<<"000";
}
else cout<<"0000";
return 0;
}
