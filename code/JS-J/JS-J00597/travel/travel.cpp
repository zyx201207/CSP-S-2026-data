#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ans="";
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans+="1";
    }else{
        ans="0000";
        cout<<ans;
        return 0;
    }
    int t1=0,t2=0;
    t1+=s1[0]-'0';
    t1=t1*10+s1[1]-'0';
    t2+=s2[0]-'0';
    t2=t2*10+s2[1]-'0';
    if(t1==t2){
        ans+="1";
    }else{
        ans+="000";
        cout<<ans;
        return 0;
    }
    if(s1[2]>='A'&&s1[2]<='C'){
        if(s2[2]>='A'&&s2[2]<='C'){
            ans+="1";
        }
        else{
            ans+="00";
            cout<<ans;
            return 0;
        }
    }
    else{
        if(s2[2]=='D'||s2[2]=='F'){
            ans+="1";
        }
        else{
             ans+="00";
             cout<<ans;
             return 0;
        }
    }
    int a,b;
    a=s1[2]-'0';
    b=s2[2]-'0';
    if(s1[2]>='A'&&s1[2]<='C'){
        if(s2[2]>='A'&&s2[2]<='C'&&(b==a-1||b==a+1)){
            ans+="1";
        }
        else ans+="0";
    }
    else{
        if(s2[2]=='D'||s2[2]=='F'){
            ans+="1";
        }
        else ans+="0";
    }
    cout<<ans;
    return 0;
}
