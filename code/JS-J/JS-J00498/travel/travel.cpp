#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,ss,t,tt;
    cin>>s>>ss>>t>>tt;
    if(s==t){cout<<1;}
    else{cout<<0;}
    if(ss[0]==tt[0]&&ss[1]==tt[1]&&s==t)cout<<1;
    else{cout<<0;}
    if(s==t){
        if(tt[0]==ss[0]&&tt[1]==ss[1]){
        if(tt[2]=='A'||tt[2]=='B'||t[2]=='C'){
            if(ss[2]=='A'||ss[2]=='B'||ss[2]=='C'){cout<<1;}
            else{cout<<0;}
        }
        else{
            if(ss[2]=='D'||ss[2]=='F'){cout<<1;}
            else{cout<<0;}
        }
        }
        else{cout<<0;}
    }
    else{cout<<0;}
    if(s==t){
        if(ss[1]==tt[1]&&ss[0]==tt[0]){
        if(ss[2]=='A'){if(tt[2]=='B'){cout<<1;}else{cout<<0;}}
        if(ss[2]=='B'){if(tt[2]=='A'||tt[2]=='C'){cout<<1;}else{cout<<0;}}
        if(ss[2]=='C'){if(tt[2]=='B'){cout<<1;}else{cout<<0;}}
        if(ss[2]=='D'){if(tt[2]=='F'){cout<<1;}else{cout<<0;}}
        if(ss[2]=='F'){if(tt[2]=='D'){cout<<1;}else{cout<<0;}}
        }
        else{cout<<0;}
    }
    else{cout<<0;}
    return 0;
}
