#include <bits/stdc++.h>
using namespace std;
string c[105],s,s1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
        if(i==1){
            cin>>c[i]>>s;
        }else{
            cin>>c[i]>>s1;
        }
    }
    if(c[1]==c[2]){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(s[0]==s1[0]&&s[1]==s1[1]){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if(s[2]=='A'&&s1[2]=='B'){
        cout<<"11";
        return 0;
    }else if(s[2]=='A'&&s1[2]=='C'){
        cout<<'1';
    }else if(s[2]=='B'&&s1[2]=='A'){
        cout<<"11";
        return 0;
    }else if(s[2]=='B'&&s1[2]=='C'){
        cout<<"11";
        return 0;
    }else if(s[2]=='C'&&s1[2]=='B'){
        cout<<"11";
    }else if(s[2]=='C'&&s1[2]=='A'){
        cout<<'1';
    }else if(s[2]=='D'&&s1[2]=='F'){
        cout<<"11";
        return 0;
    }else if(s[2]=='F'&&s1[2]=='D'){
        cout<<"11";
        return 0;
    }else{
        cout<<"00";
        return 0;
    }
    cout<<'0';
    return 0;
}
