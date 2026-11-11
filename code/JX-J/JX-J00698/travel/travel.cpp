#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c,e,f,x=0;
    string b,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        x=1;
    }
    else{
        cout<<0;
    }
    e=b[0]-'0'+b[1]-'0';
    f=d[0]-'0'+d[1]-'0';
    if(x==1 and e==f){
        cout<<1;
    }
    else{
        cout<<0;
        x=0;
    }
    if(x==1 and b[2]<='C' and d[2]<='C'){
        cout<<1;
        x=1;
    }
    else if(x==1 and b[2]>='D' and d[2]>='D'){
        cout<<1;
        x=1;
    }
    else{
        cout<<0;
        x=0;
    }
    if(x==1 and max(b[2],d[2])-min(b[2],d[2])==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
