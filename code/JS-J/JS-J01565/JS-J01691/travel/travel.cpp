#include <bits/stdc++.h>
using namespace std;
string a1,b1;
string a2,b2;
bool chk1(){
    return a1==a2;
}
bool chk2(){
    return chk1()&&(b1.substr(0,2)==b2.substr(0,2));
}
bool side(string s){
    return s.back()=='A'||s.back()=='B'||s.back()=='C';
}
bool chk3(){
    return chk2()&&side(b1)==side(b2);
}
bool chk4(){
    return chk3()&&(abs(b1.back()-b2.back())==1||(b1.back()=='D'&&b2.back()=='F')||(b1.back()=='F'&&b2.back()=='D'));
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a1>>b1;
    cin>>a2>>b2;
    cout<<chk1();
    cout<<chk2();
    cout<<chk3();
    cout<<chk4();
    return 0;
}