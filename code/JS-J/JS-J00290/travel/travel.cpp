#include<bits/stdc++.h>
using namespace std;
int main(){
    string cone,sone,ctwo,stwo;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //
    cin>>cone>>sone>>ctwo>>stwo;
    if(cone==ctwo){//tong chexiang
        cout<<"1";
        if(sone.substr(0,2)==stwo.substr(0,2)){//tong pai
            cout<<"1";
            if((sone[2]<='C'&&stwo[2]<='C')||(sone[2]>='D'&&stwo[2]>='D')){//tong pai
                cout<<"1";
                if(abs(sone[2]-stwo[2])==1){//tong pai
                    cout<<"1";

                }else{cout<<"0";}
            }else{cout<<"00";}
        }else{cout<<"000";}
    }else{cout<<"0000";}



    return 0;
}
