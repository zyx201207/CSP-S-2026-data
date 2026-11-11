#include<bits/stdc++.h>
using namespace std;
string c1;string s1;string c2;string s2;
bool check1(char a,char b){
    if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))return 1;
    else if((a=='D'||a=='F')&&(b=='D'||b=='F'))return 1;
    return 0;
}
bool check2(char a,char b){
    if(a=='A'&&b=='B')return 1;
    else if(a=='B'&&b=='C')return 1;
    else if(a=='D'&&b=='F')return 1;
    return 0;
}

int main(){
    freopen("travel.in"," r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    string cs1=s1.substr(0,2);
    string cs2=s2.substr(0,2);
    if(cs1==cs2){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    char ca1=s1[2];
    char ca2=s2[2];
    if(check1(ca1,ca2)){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(check2(ca1,ca2)||check2(ca2,ca1)){
        cout<<"1";
    }
    else{
        cout<<"0";
        return 0;
    }
    return 0;
}