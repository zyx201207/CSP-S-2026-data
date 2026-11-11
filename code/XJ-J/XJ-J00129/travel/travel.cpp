#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1;
    int a2,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<1;
    }else cout<<0;
    if(a2/10%100==b2/10%100){
        cout<<1;
    }else cout<<0;
    cout<<0;
    if(a2/10+1==b2||b2/10+1==a2){
        cout<<1;
    }else cout<<0;
    return 0;
}
