#include<iostream>
#include<cstdio>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;   
 cout<<(c1==c2);
if(c1==c2){
    string a;
    a+=s1[0];
    a+=s1[1];
string b;
b+=s2[0];
b+=s2[1];
cout<<(a==b);
if(a==b){
bool ds=s2[2]>'C';
bool ds1=s1[2]>'C';
cout<<(ds==ds1);
if(ds==ds1){
cout<<(abs(s1[2]-s2[2])==1);
}
else cout<<0;
}
else cout<<"00";
}
else cout<<"000";
    return 0;
}