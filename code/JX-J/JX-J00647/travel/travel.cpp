#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
if(c1!=c2){
cout<<"0000";
return 0;
}

cout<<1;

if(s1[0]==s2[0] and s1[1]==s2[1]){
cout<<1;

if(s1[2]<='C' and s1[2]>='A' and s2[2]<='C' and s2[2]>='A'){
cout<<1;

if((s1[2]-s2[2]==1) or (s1[2]-s2[2]==-1)){
cout<<1;
}else{
cout<<0;
}
}else{
if(s1[2]<='E' and s1[2]>='D' and s2[2]<='E' and s2[2]>='D'){
cout<<11;
}else{
cout<<"00";
}
}
}else{
cout<<"000";
}

return 0;
}
