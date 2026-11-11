#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char r[10],x[10];
    for(int i=1;i<=5;i++){
        cin>>r[i];
    }
    for(int i=1;i<=5;i++){
        cin>>x[i];
    }
    if(r[1]==x[1] && r[2]==x[2]){
        cout<<1;
        if(r[3]==x[3] && r[4]==x[4]){
            cout<<1;
            if(!(r[5]>'C' ^ x[5]>'C')){
                cout<<1;
                if(r[5]>'C' || r[5]-x[5]==1 || r[5]-x[5]==-1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0<<0;
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
