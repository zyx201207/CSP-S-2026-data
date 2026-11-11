#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int ac,bc;
    string ah,bh;
    cin>>ac>>ah>>bc>>bh;
    if(ac==bc){
        cout<<"1";
        if(ah[0]==bh[0] && ah[1]==bh[1]){
            cout<<"1";
            if((ah[2]<='C' && bh[2]<='C') || (ah[2]>='D' && bh[2]>='D')){
                cout<<"1";
                if(ah[2]-bh[2]==1 || ah[2]-bh[2]==-1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }

    return 0;
}
