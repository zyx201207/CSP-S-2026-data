#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,sss,ssss;
bool pd=false;
int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
freopen("travel.in","r",stdin);
freopen("travel.out","r",stdout);
cin>>c1>>s1>>c2>>s2;
if(c1==c2){pd=true;cout<<1;}
else{cout<<0;pd=false;}
if(pd&&s2[0]+s2[1]==s1[0]+s1[1]){cout<<1;pd=true;}
else{cout<<0;pd=false;}
if(pd){
    if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))cout<<1;
    else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))cout<<1;
    else if(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))cout<<1;
    else if(s1[2]=='D'&&s2[2]=='F')cout<<1;
    else if(s1[2]=='F'&&s2[2]=='D')cout<<1;
    else cout<<0;
}
else{pd=false;cout<<0;}
if(pd){
    if(s1[2]=='A'&&s2[2]=='B')cout<<1;
    else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))cout<<1;
    else if(s1[2]=='C'&&s2[2]=='B')cout<<1;
    else if(s1[2]=='D'&&s2[2]=='F')cout<<1;
    else if(s1[2]=='F'&&s2[2]=='D')cout<<1;
    else cout<<0;
}
else cout<<0;
return 0;
}
