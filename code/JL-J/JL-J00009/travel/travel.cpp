#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1!=a2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(b1[0]!=b2[0] || b1[1]!=b2[1]){
        cout<<"000";
        return 0;
    }
    cout<<1;

    if((b1[2]<='C'&&b2[2]>'C')||(b1[2]>'C' && b2[2]<='C')){
        cout<<"00";
        return 0;
    }cout<<1;

    if(abs(b2[2]-b1[2])>1){
        cout<<"0";
        return 0;
    }cout<<1;
    return 0;
}
//Trick||Treat!
