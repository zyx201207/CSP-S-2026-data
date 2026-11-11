#include <bits/stdc++.h>
using namespace std;
string c1;
string s1;
string c2;
string s2;
int a(char x){
    char c=x;
    if(c=='A') return 1;
    else if(c=='B') return 1;
    else if(c=='C') return 1;
    else return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2 && s1[0]==s2[0]
       && s1[1]==s2[1]) cout<<1;
    else cout<<0;
    if(c1==c2 && s1[0]==s2[0]
       && s1[1]==s2[1] && a(s1[2])==a(s2[2])) cout<<1;
    else cout<<0;
    if(s1[2]==s2[2]&& s1[0]==s2[0]
       && s1[1]==s2[1]+1|| s1[1]==s2[1]-1) cout<<1;
    else cout<<0;
return 0;
}
