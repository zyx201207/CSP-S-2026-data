#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int fun(char a,char b){
    if ((a<='C' && b<='C') || (a>'C' && b>'C')) return 1;
    else return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2) cout<<1;
    else cout<<0;
    if (s1.substr(0,2)==s2.substr(0,2)) cout<<1<<fun(s1[2],s2[2]);
    else cout<<00;
    if (abs(s1[2]-s2[2])==1 && !(s1[2]=='D' && s2[2]=='C') && !(s1[2]=='C' && s2[2]=='D')) cout<<1;
    else cout<<0;
    return 0;
}
