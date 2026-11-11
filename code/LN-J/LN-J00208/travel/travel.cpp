#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2,s2;
string str;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2){
        str+='1';
    }else{
        str+="0000";
        cout<<str;
        return 0;
    }

    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        str+='1';
    }else{
        str+="000";
        cout<<str;
        return 0;
    }

    if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
        str+="00";
        cout<<str;
        return 0;
    }

    if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))){
        str+='1';
    }else{
        str+="00";
        cout<<str;
        return 0;
    }

    if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')){
        str+='1';
    }else{
        str+='0';
    }
    cout<<str;
    return 0;
}
