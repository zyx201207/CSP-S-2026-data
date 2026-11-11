#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1==a2)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(b1.substr(0,2)==b2.substr(0,2))cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(b1[2]=='A'){
        if(b2[2]=='B')cout<<11;
        else if(b2[2]=='C')cout<<10;
        else cout<<"00";
        return 0;
    }
    if(b1[2]=='B'){
        if(b2[2]=='A'||b2[2]=='C')cout<<11;
        else cout<<"00";
        return 0;
    }
    if(b1[2]=='C'){
        if(b2[2]=='B')cout<<11;
        else if(b2[2]=='A')cout<<10;
        else cout<<"00";
        return 0;
    }
    if((b1[2]=='D'&&b2[2]=='F')||(b2[2]=='D'&&b1[2]=='F')){
        cout<<11;
    }
    else cout<<"00";
    return 0;
}
