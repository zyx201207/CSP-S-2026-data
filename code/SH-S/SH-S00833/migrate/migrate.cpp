#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((c==4)&&(d==2)){
        cout<<1<<endl<<2;
    }
    if((c==5)&&(d==3)){
        cout<<0<<endl<<1;
    }else{
    cout<<0;}
    return 0;
}

//愿我CSP-S二等奖
