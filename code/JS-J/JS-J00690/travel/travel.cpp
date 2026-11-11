#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string s,s1,b,b1;
cin>>s>>s1>>b>>b1;
if(s!=b){
cout<<"0000";
return 0;
}
if(s=="01"||s=="16"||b=="01"||b=="16"){
cout<<"0000";
return 0;
}string c1=s1.substr(2,1),d1=b1.substr(2,1);
string c=s1.substr(0,2),d=b1.substr(0,2);
cout<<1;
bool t=0;
if(c==d){
    cout<<1;
    t=1;
}else{
cout<<0;
}bool f=0;
if(((c1>"C"&&d1>"C")||(c1<="C"&&d1<="C"))&&t==1){
    cout<<1;
    f=1;
}else{
cout<<0;
}
for(int i=0;i<c1.size();i++){
        int g=c1[i]-'A',v=d1[i]-'A';
if((g+1==v||g-1==v)&&f==1){
    cout<<1;
}else{
cout<<0;
}
}
    return 0;
}
