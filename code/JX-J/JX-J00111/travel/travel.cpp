#include<bits/stdc++.h>
using namespace std;
int lc,rc;
string ls,rs;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>lc>>ls>>rc>>rs;
    if(lc==rc) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(ls[0]==rs[0]&&ls[1]==rs[1]){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if((ls[2]<='F'&&ls[2]>='D'&&rs[2]<='F'&&rs[2]>='D')||(ls[2]<='C'&&ls[2]>='A'&&rs[2]<='C'&&rs[2]>='A')){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(abs(rs[2]-ls[2])==1) cout<<"1";
    else cout<<"0";
    return 0;
}
