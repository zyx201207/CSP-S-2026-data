#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,c2,s1,s2;
char side(char ch){
    if(ch>='A'&&ch<='C')return 'l';
    if(ch>='D'&&ch<='F')return 'r';
}
bool next(string a,string b){
    string num1=a.substr(0,2),num2=b.substr(0,2);
    if(num1==num2){
        if(abs(a[2]-b[2])==1)return true;
        else return false;
    }
    else if(abs(stoll(num1)-stoll(num2))==1){
        if(s1[2]==s2[2])return true;
        else return false;
    }
    else return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]+s1[1]==s2[0]+s2[1])cout<<1;
        else cout<<0;
        if(s1[0]+s1[1]==s2[0]+s2[1]&&side(s1[2])==side(s2[2]))cout<<1;
        else cout<<0;
        if(side(s1[2])==side(s2[2])&&next(s1,s2))cout<<1;
        else cout<<0;
    }
    else cout<<"0000"<<'\n';
}