#include<bits/stdc++.h>
using namespace std;
string a,s,d,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s>>d>>f;
    if(a!=d){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s[0]!=f[0]||f[1]!=s[1]){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(f[2]=='D'||f[2]=='E')||
       (s[2]=='D'||s[2]=='E')&&(f[2]=='A'||f[2]=='B'||f[2]=='C')){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(s[3]=='A'&&f[3]=='C'||s[3]=='C'&&f[3]=='A'){
        cout<<0;
        return 0;
    }
    cout<<1;
    return 0;
}
