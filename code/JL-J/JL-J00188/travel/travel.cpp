#include<bits/stdc++.h>
using namespace std;
int main () {
    freopen("travel","r",stdin);
    freopen("travel","w",stdout);
    char x[10001],y[10001],z[10001],m[10001];
    int i;
    cin>>x>>y>>z>>m;
    for( i=0;i<=2;i++){
        if(x[i]!=z[i]){
            cout<<0<<0<<0<<0;
            break;
        }
    }
    if(i>=2){
        cout<<1;
        for(int i=0;i<=1;i++){
        if(y[i]!=m[i]){
            cout<<0;
            break;
        }
    }
    if(i>=1){
        cout<<1;
    }
    if((y[2]=='A' || y[2]=='B' || y[2]=='C') && (m[2]=='A' || m[2]=='B' || m[2]=='C') ){
        cout<<1;
        if(y[2]=='A' && m[2]=='C'){
            cout<<0;
            return 0;
        }
        else cout<<1;
    }
    else if((y[2]=='D' || y[2]=='F') && (m[2]=='D' || m[2]=='F')){
        cout<<1;
        if(y[2]=='A' && m[2]=='C'){
            cout<<0;
            return 0;
        }
        else cout<<1;
    }
    else cout<<0;
    }


return 0;
}
