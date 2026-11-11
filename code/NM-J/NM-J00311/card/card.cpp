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
            int g1,g2;
            if(c1=='F' || c1=='D'){
                g1=1;
            }else{
                g1=2;
            }
            if(c2=='F' || c2=='D'){
                g2=1;
            }else{
                g2=2;
            }
            if(g1==g2){
                cout<<1;
                if(b1+1==b2 || b1-1==b2 || c1+1==c2 || c1-1==c2)cout<<1;
                else cout<<"0";
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
