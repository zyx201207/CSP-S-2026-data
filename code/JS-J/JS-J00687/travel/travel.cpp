#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string ans="";
    if(c1==c2)ans+='1';
    else {
        ans="0000";
        cout<<ans;
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        ans+='1';
    }
    else {
        ans+="000";
        cout<<ans;
        return 0;
    }
    if(s1[2]=='A'){
        if(s2[2]=='B'||s2[2]=='C')ans+='1';
        else ans+='0';
        if(s2[2]=='B')ans+='1';
        else ans+='0';
    }
    else if(s1[2]=='B'){
        if(s2[2]=='A'||s2[2]=='C')ans+="11";
        else ans+="00";
    }
    else if(s1[2]=='C'){
        if(s2[2]=='A'||s2[2]=='B')ans+='1';
        else ans+='0';
        if(s2[2]=='B')ans+='1';
        else ans+='0';
    }
    else if(s1[2]=='D'){
        if(s2[2]=='F')ans+="11";
        else ans+="00";
    }
    else if(s1[2]=='F'){
        if(s2[2]=='F'){
            if(s2[2]=='D')ans+="11";
            else ans+="00";
        }
    }
    cout<<ans;
    return 0;
}
