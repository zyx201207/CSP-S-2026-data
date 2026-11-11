#include <bits/stdc++.h>
using namespace std;
long long a1,a2;
string b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    int a=(b1[0]-'0')*10+(b1[1]-'0'),b=(b2[0]-'0')*10+(b2[1]-'0');
    if(a1==a2){
        cout<<1;
    }else{
        cout<<0;
    }if(a1==a2&&a==b){
        cout<<1;
    }else{
        cout<<0;
    }if(a1==a2&&a==b&&((b1[2]<='C'&&b2[2]<='C')||(b1[2]>'C'&&b2[2]>'C'))){
        cout<<1;
    }else{
        cout<<0;
    }if(a1==a2&&a==b&&((b1[2]<='C'&&b2[2]<='C')||(b1[2]>'C'&&b2[2]>'C'))&&abs(b1[2]-b2[2])==1){
        cout<<1;
    }else{
        cout<<0;
    }return 0;
}
