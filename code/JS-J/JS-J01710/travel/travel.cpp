#include<bits/stdc++.h>
using namespace std;
int main(){
freopen ("travel.in","r",stdin);
freopen ("travel.out","w",stdout);
bool tj=false,tp=false,tc=false,xl=false;
string a,a1,b,b1;
cin>>a>>a1>>b>>b1;
if(a==b) tj=true;
if(tj){
if(a1[0]==b1[0]&&a1[1]==b1[1]) tp=true;
if(tp==true){
    if(a1[2]<='C'&&b1[2]<='C') tc=true;
    else if(a1[2]>='D'&&b1[2]>='D') tc=true;
}
if(tc==true){
    if((a1[2]=='D'&&b1[2]=='F')||(b1[2]=='D'&&a1[2]=='F')) xl=true;
    if(abs(a1[2]-b1[2])==1) xl=true;
}
}
cout<<tj<<tp<<tc<<xl;
return 0;
}
