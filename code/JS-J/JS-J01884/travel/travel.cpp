#include<bits/stdc++.h>
using namespace std;
string b1,b2;
int a1,a2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    if(a1==a2) cout<<1;
    else {
        cout<<"0000";return 0;
    }
    int x=(b1[0]-'0')*10+(b1[1]-'0'),y=(b2[0]-'0')*10+(b2[1]-'0');
    if(x==y) cout<<1;
    else {
        cout<<"000";return 0;
    }
    if((b1[2]<='C'&&b2[2]<='C')||(b1[2]>='D'&&b2[2]>='D')){
        cout<<1;
    }
    else {
        cout<<"00";return 0;
    }
    if(abs(b1[2]-b2[2])==1){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
