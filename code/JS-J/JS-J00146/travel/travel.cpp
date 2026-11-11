#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<'1';
    }else{
        cout<<"0000";
        return 0;
    }

    if(s1.substr(0,2)==s2.substr(0,2)){
        cout<<'1';
    }else{
        cout<<"000";
        return 0;
    }

    if((int(s1[2])>=65&&int(s1[2])<=67&&int(s2[2])>=65&&int(s2[2])<=67)||(int(s1[2])>=68&&int(s1[2])<=69&&int(s2[2])>=68&&int(s2[2])<=69)){
        cout<<'1';
    }else{
        cout<<"00";
        return 0;
    }

    if(abs(int(s1[2])-int(s2[2]))==1){
        if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
            cout<<'0';
        }else{
            cout<<'1';
        }
    }else{
        cout<<'0';
    }
    return 0;
}
