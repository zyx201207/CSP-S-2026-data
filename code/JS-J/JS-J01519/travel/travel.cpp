#include <bits/stdc++.h>
using namespace std;
string s1,s2,b1,b2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s1>>s2>>b1>>b2;
    if(s1==b1) cout<<"1";
    else cout<<"0";
    if(s1==b1&&s2[0]==b2[0]&&s2[1]==b2[1]) cout<<"1";
    else cout<<"0";
    if(s1==b1&&s2[0]==b2[0]&&s2[1]==b2[1]){
        if(s2[2]=='A'){
            if(b2[2]=='B') cout<<"11";
            else if(b2[2]=='C') cout<<"10";
            else cout<<"00";
        }
        if(s2[2]=='B'){
            if(b2[2]=='A'&&b2[2]=='C') cout<<"11";
            else cout<<"00";
        }
        if(s2[2]=='C'){
            if(b2[2]=='B') cout<<"11";
            else if(b2[2]=='A') cout<<"10";
            else cout<<"00";
        }
        if(s2[2]=='D'){
            if(b2[2]=='F') cout<<"11";
            else cout<<"00";
        }
        if(s2[2]=='F'){
            if(b2[2]=='D') cout<<"11";
            else cout<<"00";
        }
    }
    else cout<<"00";
    return 0;
}
