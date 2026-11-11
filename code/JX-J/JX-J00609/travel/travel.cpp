#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,s,d,f;
cin>>a>>s>>d>>f;
if(a==d){
    cout<<1;
}else{
cout<<0;
}
if((s[0]==f[0])&&(s[1]==f[1])){
        cout<<1;
    if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(f[2]=='A'||f[2]=='B'||f[2]=='C')){
    cout<<1;
}else if((f[2]=='F'||f[2]=='D')&&(s[2]=='F'||s[2]=='D')){
cout<<1;
}else{
cout<<0;
}
}else{
cout<<0<<0;
}
if(s[2]==f[2]-1||s[2]==f[2]+1){
    cout<<1;
}else{
    cout<<0;
}
return 0;
}
