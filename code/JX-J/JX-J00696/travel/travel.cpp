#include<bits/stdc++.h>
using namespace std;
int main(){
    string a[2],b[2];
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a[0]>>a[1]>>b[0]>>b[1];
    for(int i=0;i<2;i++){
    if(a[0][i]!=b[0][i]){
        cout<<"0000";
        return 0;
    }
    }
    cout<<"1";
    for(int i=0;i<2;i++){
        if(a[1][i]!=b[1][i]){
            cout<<"000";
            return 0;
        }
    }
    cout<<"1";
    if((a[1][2]>'C'&&b[1][2]>'C')||(a[1][2]<='C'&&b[1][2]<='C')){
        cout<<"1";
        if(max(a[1][2],b[1][2])-min(a[1][2],b[1][2])==1){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }else{
        cout<<"00";
    }
    return 0;
}
