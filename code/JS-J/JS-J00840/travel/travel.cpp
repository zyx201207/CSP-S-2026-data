#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;bool a,b,c,d;
bool check(){
    if(s1[2]=='A'){
        if(s2[2]=='B')return 1;
    }
    if(s1[2]=='B'){
        if(s2[2]=='C'||s2[2]=='A')return 1;
    }
    if(s1[2]=='C'){
        if(s2[2]=='B')return 1;
    }
    if(s1[2]=='D')if(s2[2]=='F')return 1;
    if(s1[2]=='F')if(s2[2]=='D')return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){a=1;}
    if(a&&s1.substr(0,2)==s2.substr(0,2)){b=1;}
    if(a&&b){
        if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')c=1;}
        else
            if(s2[2]=='D'||s2[2]=='F')c=1;
        d=check();
    }
    cout<<a<<b<<c<<d;
    return 0;
}
