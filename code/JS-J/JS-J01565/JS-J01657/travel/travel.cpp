#include<bits/stdc++.h>
using namespace std;

string ans="";
string c1,s1,c2,s2;
bool check(){
    char q1=s1[2],q2=s2[2];
    if(int(q1)<='C'&&int(q2)<='C'){
        return 1;
    }
    if(int(q1)>='D'&&int(q2)>='D'){
        return 1;
    }
    return 0;
}
bool check2(){

    char q1=s1[2],q2=s2[2];

    if(q1=='D'||q2=='D'){
        return 1;
    }
    if(abs(int(q1)-int(q2))==1){
        return 1;
    }
    return 0;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool f=1;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans+="1";
    }else{
        ans+="0";
        f=0;
    }
    if(f&&s1.substr(0,2)==s2.substr(0,2)){
        ans+="1";
    }else{
        ans+="0";
        f=0;
    }
    if(f&&check()){
        ans+="1";
    }else{
        ans+="0";
        f=0;
    }
    if(f&&check2()){
        ans+="1";
    }else{
        ans+="0";
        f=0;
    }
    cout<<ans;
    return 0;
}
