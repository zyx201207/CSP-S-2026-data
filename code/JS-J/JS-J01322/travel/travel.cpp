#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f1,f2,f3,f4;
int pd1(string sa,string sb){
    if(sa[0]!=sb[0]||sa[1]!=sb[1]){
        return 1;
    }
    return 0;
}
int pd2(char ca,char cb){
    if((ca>='A'&&ca<='C')&&(cb=='D'||cb=='F')){
        return 1;
    }
    if((cb>='A'&&cb<='C')&&(ca=='D'||ca=='F')){
        return 1;
    }
    return 0;
}
int pd3(char ca,char cb){
    if(ca=='A'&&cb!='B'){
        return 1;
    }
    if(ca=='B'&&cb!='A'&&cb!='C'){
        return 1;
    }
    if(ca=='C'&&cb!='B'){
        return 1;
    }
    if(ca=='D'&&cb!='F'){
        return 1;
    }
    if(ca=='F'&&cb!='D'){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    if(pd1(s1,s2)){
        cout<<"1000";
        return 0;
    }
    if(pd2(s1[2],s2[2])){
        cout<<"1100";
        return 0;
    }
    if(pd3(s1[2],s2[2])){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
