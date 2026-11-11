#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
string a,b,c,d,e="",f="",g;
cin>>a>>b>>c>>d;
if(a==c&&a!="01"&&a!="16"){
    cout<<"1";
}else{
    cout<<"0000";
    return 0;
}
for(int i=0;i<2;i++){
    e=e+b[i];
}
for(int i=0;i<2;i++){
    f=f+d[i];
}
if(e==f){
    cout<<"1";
}else{
    cout<<"000";
    return 0;
}
if(((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))||((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))){
    cout<<"1";
}else{
    cout<<"00";
    return 0;
}
if(b[2]==d[2]){
    cout<<"0";
    return 0;
}
if(b[2]=='B'||d[2]=='B'||b[2]=='D'||b[2]=='F'){
    cout<<"1";
}else{
    cout<<"0";
}
return 0;
}

