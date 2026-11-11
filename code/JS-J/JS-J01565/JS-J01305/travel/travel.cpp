#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;string s,t;cin>>a>>s>>b>>t;
    cout<<(a==b)\
        <<(a==b&&s[0]==t[0]&&s[1]==t[1])\
        <<(a==b&&s[0]==t[0]&&s[1]==t[1]&&(s[2]<'D'&&t[2]<'D'||s[2]>'C'&&t[2]>'C'))\
        <<(a==b&&s[0]==t[0]&&s[1]==t[1]&&(s[2]<'D'&&t[2]<'D'&&abs(s[2]-t[2])==1/*ABC*/||s[2]>'C'&&t[2]>'C'/*DF/*/));
    return 0;
}
