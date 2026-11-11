#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool solve(char a,char b){
    if(a>b) swap(a,b);
    if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='A'&&b=='C')||(a=='D'&&b=='F')){
        return true;
    }
    return false;
}
bool check(char a,char b){
    if(a>b) swap(a,b);
    if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')){
        return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&(s1.substr(0,2)==s2.substr(0,2))){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&(s1.substr(0,2)==s2.substr(0,2))&&solve(s1[2],s2[2])){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&(s1.substr(0,2)==s2.substr(0,2))&&solve(s1[2],s2[2])&&check(s1[2],s2[2])){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
