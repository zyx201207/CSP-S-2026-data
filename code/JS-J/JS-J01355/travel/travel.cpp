#include<bits/stdc++.h>
using namespace std;
string cxs,zw,cxs1,zw1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cxs>>zw>>cxs1>>zw1;
    if(cxs==cxs1){
        cout<<'1';
        if(zw[0]==zw1[0] && zw[1]==zw1[1]){
            cout<<'1';
            if((zw[2]<='C' && zw1[2]<='C') || (zw[2]>'C' && zw1[2]>'C')){
                cout<<'1';
                if(abs(zw[2]-zw1[2])==1 || (zw[2]>'C' && zw1[2]>'C'))cout<<'1';
                else cout<<'0';
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
return 0;
}
