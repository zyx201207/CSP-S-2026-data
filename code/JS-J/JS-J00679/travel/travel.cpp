#include<bits/stdc++.h>
using namespace std;
int a,b,a1,b1;
char k1,k2;
string s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>a1>>k1>>b>>b1>>k2;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    s=s+"1";
    if(a1==b1){
        s=s+"1";

        if(k1<='C'&&k2<='C'||(k1>'C'&&k2>'C')){
            s=s+"1";


        }else s=s+"0";
    }else{
        s=s+"00";
    }
    cout<<s;
    if(s[2]=='1'){
            if(k1=='A'&&k2=='B'||(k1=='B'&&k2=='C')||(k1=='D'&&k2=='F'))cout<<1;
            else cout<<0;
    }
    return 0;
}
