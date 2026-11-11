#include<bits/stdc++.h>
using namespace std;
bool f=true;
string c1,s1,c2,s2;
string ans;
bool check(char a,char b){
    bool af=false,bf=false;
    if(a>='A' and a<='C') af=true;
    if(b>='A' and b<='C') bf=true;
    return af==bf;
}
bool check2(char a,char b,bool flag){
    if(a=='A' and b=='B') return true;
    if(a=='B' and b=='C') return true;
    if(a=='D' and b=='F') return true;
    if(flag) return check2(b,a,false);
    return false;
}
int main(){
    freopen("travel.in","r",stdin); freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2; ans="0000";
    if(c1==c2 and f) ans[0]='1';
    else f=false;
    if(s1[0]==s2[0] and s1[1]==s2[1] and f) ans[1]='1';
    else f=false;
    if(check(s1[2],s2[2]) and f) ans[2]='1';
    else f=false;
    if(check2(s1[2],s2[2],true) and f) ans[3]='1';
    cout<<ans;
    return 0;
}
