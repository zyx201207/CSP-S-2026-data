#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
char a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    a=s1[2];
    b=s2[2];
    if(c1==c2) cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(s1[0]+s1[1]==s2[0]+s2[1]) cout<<1;
    else{
        cout<<0<<0<<0;
        return 0;
    }
    if(a=='A'&&(b=='B'||b=='C')||a=='B'&&(b=='A'||b=='C')||a=='C'&&(b=='B'||b=='A')||a=='D'&&b=='F'||a=='F'&&b=='D'){
        cout<<1;
    }else{
        cout<<0<<0;
        return 0;
    }
    if(a=='D'&&b=='F'||a=='F'&&b=='D'||a=='A'&&b=='B'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='B'){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
