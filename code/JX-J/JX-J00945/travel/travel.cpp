#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3){
        cout<<"0000";
        return;
    }else{
        cout<<"1";
    }
    string z1="",z3="";
    char z2=s2[2],z4=s4[2];
    z1=z1+s2[0]+s2[1];
    z3=z3+s4[0]+s4[1];
    if(z4=='F'){
        z4='E';
    }
    if(z1!=z3){
        cout<<"000";
        return;
    }else{
        cout<<"1";
    }
    if(((z2<='C'&&z2>='A')&&((z4<='C'&&z4>='A'))||((z2<='F'&&z2>='D')&&((z4<='F'&&z4>='D'))))){
       cout<<"1";
    }else{
        cout<<"00";
        return;
    }
    if((z2-z4)==1||(z2-z4)==-1){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}
