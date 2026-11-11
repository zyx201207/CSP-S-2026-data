#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int c1,c2,s1,s2;
char a,b;
cin>>c1>>s1>>a>>c2>>s2>>b;
if(c1==c2){
    cout<<1;
}
else{
    cout<<"0000";
    return 0;
}
if(s1==s2){
    cout<<1;
}
else{
    cout<<"000";
    return 0;
}
if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='A'&&b=='C'||a=='C'&&b=='A'||
   a=='D'&&b=='F'||a=='F'&&b=='D'||a=='C'&&b=='B'||a=='B'&&b=='C'){
    cout<<1;
}
else{
    cout<<"00";
    return 0;
}
if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='D'&&b=='F'||
   a=='F'&&b=='D'||a=='C'&&b=='B'||a=='B'&&b=='C'){
    cout<<1;
}
else{
    cout<<"0";
    return 0;
}
fclose(stdin);
fclose(stdout);
return 0;
}
