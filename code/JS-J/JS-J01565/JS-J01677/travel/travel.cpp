#include<bits/stdc++.h>
using namespace std;
int main(){
    string x1,x2,y1,y2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x1;
    cin>>x2;
    cin>>y1;
    cin>>y2;
    for(int i=0;i<2;i++){
        if(x1[i]!=y1[i]){
            cout<<"0000";
            return 0;
        }
    }
    cout<<1;
    for(int i=0;i<2;i++){
        if(x2[i]!=y2[i]){
            cout<<"000";
            return 0;
        }
    }
    cout<<1;
    if(x2[2]<='C'){
        if(y2[2]<='C'){
            cout<<1;
        }else cout<<0;
    }else if(x2[2]>'C'){
        if(y2[2]>'C'){
            cout<<1;
        }else cout<<0;
    }
    if(x2[2]<'C'){
        if(y2[2]==x2[2]+1 || y2[2]==x2[2]+1){
            cout<<1;
        }else cout<<0;
    }else if(x2[2]>'C'){
        if(y2[2]==x2[2]+1 || y2[2]==x2[2]+1){
            cout<<1;
        }else cout<<0;
    }else {
        if(y2[2]==x2[2]-1){
            cout<<1;
        }else cout<<0;
    }
    return 0;
}
