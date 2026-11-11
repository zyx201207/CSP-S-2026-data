#include <bits/stdc++.h>
using namespace std;
string s,c,d,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>c>>d>>f;
    if(s==d){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(c[0]==f[0]&&c[1]==f[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if((c[2]=='A'&&(f[2]=='B'||f[2]=='C'))||(c[2]=='B'&&(f[2]=='A'||f[2]=='C'))||(c[2]=='C'&&(f[2]=='B'||f[2]=='A'))||(c[2]=='D'&&f[2]=='F')||(c[2]=='F'&&f[2]=='D')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((c[2]=='D'&&f[2]=='F')||(c[2]=='F'&&f[2]=='D')||(c[2]=='A'&&f[2]=='B')||(c[2]=='B'&&f[2]=='A')||(c[2]=='B'&&f[2]=='C')||(c[2]=='C'&&f[2]=='B')){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
