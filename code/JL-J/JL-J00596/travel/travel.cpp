#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool c(string f,string g){
    char h=f[2],l=g[2];
    bool ans=0;
    if((h=='F'&&l=='D')||(h=='D'&&l=='F')||(h=='A'&&l=='B')||(h=='B'&&l=='A')||(h=='B'&&l=='C')||(h=='C'&&l=='B')){
        ans=1;
    }
    return ans;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
//-------------------------------------------------------------------------

    if(c1==c2){
        cout<<1;
    }
    else {
        cout<<"0000";
        return 0;
    }

//-------------------------------------------------------------------------
    if(s2[1]==s1[1]&&s1[0]==s2[0]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
//-------------------------------------------------------------------------
    bool a=0;
    if((s1[2]=='D')||(s1[2]=='F')){
        if((s2[2]=='D')||(s2[2]=='F')){
            cout<<1;
            a=1;
        }
    }
    else{
        if((s2[2]=='C')||(s2[2]=='B')||(s1[2]=='A')){
            cout<<1;
            a=1;
        }
    }
    if(!a){
        cout<<"00";
        return 0;
    }

//-------------------------------------------------------------------------
    if(c(s1,s2)){
        cout<<1;
    }
    else {
        cout<<0;
    }
}
