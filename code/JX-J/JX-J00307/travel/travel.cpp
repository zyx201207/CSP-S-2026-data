#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","l",stdin);
    freopen("travel.out","w",stdout);
    string a,s,d,f;
    cin>>a>>s>>d>>f;
    if(a==d){
        cout<<"11";
        if((s[2]=='A'||s[2]=='B'||s[2]=='C'&&f[2]=='D'||f[2]=='F')||(f[2]=='A'||f[2]=='B'||f[2]=='C'&&s[2]=='D'||s[2]=='F')){
            cout<<"00";
            return 0;
        }
        else{
            cout<<"1";
        }
        if(s[2]=='A'||s[2]=='C'&&f[2]=='B'||f[2]=='A'||f[2]=='C'&&s[2]=='B'){
            cout<<"1";
            return 0;
        }
        if(s[2]=='A'||s[2]=='C'&&f[2]!='B'||f[2]=='A'||f[2]=='C'&&s[2]!='B'){
            cout<<"0"<<" ";
            return 0;
        }
        if(s[2]=='D'&&f[2]=='F'||f[2]=='D'&&s[2]=='F'){
            cout<<"1";
            return 0;
        }
        if(s[2]!='D'&&f[2]!='F'||f[2]=='D'&&s[2]=='F'){
            cout<<"0"<<" ";
            return 0;
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
