#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a,b;
    string s,r;
    cin>>a>>s>>b>>r;
    long long k1=(s[0]-'0')*10+(s[1]-'0');
    long long k2=(r[0]-'0')*10+(r[1]-'0');
    if(a==b){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(k1==k2){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(s[2]<='C'&&r[2]<='C'){
        cout<<1;
    }
    else if(s[2]>'C'&&r[2]>'C'){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(abs(s[2]-r[2])==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
