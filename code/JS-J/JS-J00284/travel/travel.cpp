#include<bits/stdc++.h>
using namespace std;
int c11,c12,q11,q12;
char s11,s12;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c11>>q11>>s11>>c12>>q12>>s12;
    if(c11==c12) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(c11==c12&&q11==q12) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(c11==c12&&q11==q12&&(s11<='C'&&s12<='C')||(s11>'C'&&s12>'C')) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(c11==c12&&q11==q12&&((s11<='C'&&s12<='C')||(s11>'C'&&s12>'C'))&&(s11==s12+1||s12==s11+1)) cout<<1;
    else cout<<0;
    return 0;
}
