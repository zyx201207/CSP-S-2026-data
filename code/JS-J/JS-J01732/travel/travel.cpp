#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string Rt,Rs,Xt,Xs;
    cin>>Rt>>Rs>>Xt>>Xs;
    if(Rt==Xt){
        cout<<1;
        if(Rs[0]==Xs[0]&&Rs[1]==Xs[1]){
            cout<<1;
            if((Rs[2]<'D')==(Xs[2]<'D')){
                cout<<1;
                if(Rs[2]+1==Xs[2]||Rs[2]-1==Xs[2]){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}