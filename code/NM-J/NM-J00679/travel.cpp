#include<bits/stdc++.h>
using namespace std;
int main(){
//freoppen("tavel","t""stdin");
//freoppen("tavel","t""stdin");

string c1,s1,c2,s2;
string b,c;
string a;
cin>>c1>>s2>>c2>>s2;
if(c1==c2){
   a[1]=1;
}
else{a[1]=0;}
for(int i=1;i<=s1.size();i++){
    if(s1[i]>'0'&&s1[i]<5){
       b=s1[i];
    }
}
for(int i=1;i<=s2.size();i++){
    if(s2[i]>'0'&&s2[i]<5){
       c=s2[i];
       }
    }
if(b==c){
a[2]=1;
}
if(c1!=c2&&s1!=s2){
    cout<<"0000";
}
if(s1[1]==s2[1]&&s1[2]==s2[2]&&c1==c2){
    cout<<"1111";
}
if(c1==c2){
    cout<<"1000";
}
return 0;
}
