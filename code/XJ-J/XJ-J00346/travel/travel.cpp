#include <bits/stdc++.h>
using namespace std;
string c1n,s1n,c2n,s2n;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1n>>s1n>>c2n>>s2n;
    if(c1n==c2n) {
        cout<<1;
    }else {
        cout<<"0000";
        return 0;
    }
    if((int)s1n[0]==(int)s2n[0]&&(int)s1n[1]==(int)s2n[1]) {
        cout<<1;
    }else {
        cout<<"000";
        return 0;
    }
    if((s1n[2]=='A'&&(s2n[2]=='B'||s2n[2]=='C'))||(s1n[2]=='D'&&s2n[2]=='E')||(s1n[2]=='B'&&(s2n[2]=='A'||s2n[2]=='C'))||(s1n[2]=='E'&&s2n[2]=='D')||(s1n[2]=='C'&&(s2n[2]=='A'||s2n[2]=='B'))) {
        cout<<1;
    }else {
        cout<<"00";
        return 0;
    }
    if((s1n[2]=='A'&&s2n[2]=='B')||(s1n[2]=='B'&&s2n[2]=='A')||(s1n[2]=='B'&&s2n[2]=='C')||(s1n[2]=='C'&&s2n[2]=='B')||(s1n[2]=='D'&&s2n[2]=='E')||(s1n[2]=='E'&&s2n[2]=='D')) {
        cout<<1;
    }else {
        cout<<0;
    }
    return 0;
}