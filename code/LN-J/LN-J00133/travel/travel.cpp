
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1,a2,b2;
    char c1,c2;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    if(a1==a2){
        cout<<1;
        if(b1==b2){
            cout<<1;
            if((c1<='C' && c2<='C') || (c1>='D' && c2>='D')){
                cout<<1;
                if(abs(c1-c2)==1){
                    cout<<1;
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
