#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[4],s1[4],c2[4],s2[4];
    cin>>c1[1]>>c1[2];
    cin>>s1[1]>>s1[2]>>s1[3];
    cin>>c2[1]>>c2[2];
    cin>>s2[1]>>s2[2]>>s2[3];

    if(c1[1]==c2[1] && c1[2]==c2[2]) cout<<1;
    else cout<<0;

    if(s1[1]==s2[1] && s1[2]==s1[2]) cout<<1;
    else cout<<0;

    if(s1[3]=='A'&&s2[3]=='B' || s1[3]=='A'&&s2[3]=='C' || s1[3]=='B'&&s2[3]=='A' || s1[3]=='B'&&s2[3]=='C' || s1[3]=='C'&&s2[3]=='B' || s1[3]=='C'&&s2[3]=='A'){
        cout<<1;
        if(s1[3]=='A'&&s2[3]=='B' || s1[3]=='B'&&s2[3]=='C' || s1[3]=='B'&&s2[3]=='A' || s1[3]=='C'&&s2[3]=='B') cout<<1;
        else cout<<0;
    }else{
        if(s1[3]=='D'&&s2[3]=='F' || s1[3]=='F'&&s2[3]=='D'){
            cout<<1;
            cout<<1;
        }else{
            cout<<0;
            cout<<0;
        }
    }

    return 0;
}
