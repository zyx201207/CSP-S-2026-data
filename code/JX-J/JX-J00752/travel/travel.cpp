#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","W",stdout);
    string a,a1;
    string b,c;
    for(int i=1;i<=2;i++){
        if(i==1){
            cin>>a;
            cin>>b;
        }else cin>>a1>>c;
    }
    if(a==a1&&a!="01"&&a!="16"){
        cout<<1;
    }else {
        cout<<"0000";
        return 0;
    }
    if(b[0]==c[0]&&b[1]==c[1]){
        cout<<1;
        if(b[2]!=c[2]&&abs(b[2]-c[2])==1){
            if(b[2]=='C'&&c[2]=='D'||b[2]=='D'&&c[2]=='C'){
                cout<<"00";
            }else cout<<"11";
        }else cout<<"10";
    }else cout<<"000";

    return 0;
}
