#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,x,s1,x1;
    cin>>s>>x>>s1>>x1;
    if(s==s1){
        cout<<1;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(x[0]==x1[0] && x[1]==x1[1]){
        cout<<1;
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }
    if(x[2]=='A' && x1[2]=='B' || (x[2]=='B' && x1[2]=='A')){
        cout<<1;
    }
    else if((x[2]=='A' && x1[2]=='C') || (x[2]=='C' && x1[2]=='A')){
        cout<<1;
    }
    else if((x[2]=='C' && x1[2]=='B') || (x[2]=='B' && x1[2]=='C') ){
        cout<<1;
    }
    else if((x[2]=='D' && x1[2]=='F') || (x[2]=='F' && x1[2]=='D')){
        cout<<1;
    }
    else{
        cout<<0<<0;
        return 0;
    }
    if((x[2]=='A'&&x1[2]=='B') || (x[2]=='B'&&x1[2]=='A')){
        cout<<1;
    }
    else if((x[2]=='C'&&x1[2]=='B') || (x[2]=='B'&&x1[2]=='C')){
        cout<<1;
    }
    else if((x[2]=='D'&&x1[2]=='F') || (x[2]=='F'&&x1[2]=='D')){
        cout<<1;
    }
    else{
        cout<<0;
        return 0;
    }
    return 0;
}

