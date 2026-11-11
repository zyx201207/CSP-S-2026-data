#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int a,b;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin>>a>>s1>>b>>s2;
    if(a==b) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[1]==s2[1] && s1[0]==s2[0]){
        cout<<"1";
        if(s1[2]=='A' && s2[2]=='B') cout<<"11";
        else if(s1[2]=='B' && s2[2]=='A') cout<<"11";
        else if(s1[2]=='A' && s2[2]=='C') cout<<"10";
        else if(s1[2]=='C' && s2[2]=='A') cout<<"10";
        else if(s1[2]=='B' && s2[2]=='C') cout<<"11";
        else if(s1[2]=='C' && s2[2]=='B') cout<<"11";
        else if(s1[2]=='D' && s2[2]=='E') cout<<"11";
        else if(s1[2]=='E' && s2[2]=='D') cout<<"11";
        else cout<<"00";
    }
    else cout<<"000";
    return 0;
}
