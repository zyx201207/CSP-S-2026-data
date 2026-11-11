#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool t=1;
    if(c1==c2)cout<<1;
    else {
        cout<<0;
        t=0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&t==1)cout<<1;
    else {
        cout<<0;
        t=0;
    }
    if((s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C')&&t==1)cout<<1;
    else{
        cout<<0;
        t=0;
    }
    if((s1[2]=='A'&&s2[2]=='B'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')&&t==1)cout<<1;
    else cout<<0;
    return 0;
}
