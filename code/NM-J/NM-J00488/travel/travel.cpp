#include <bits/stdc++.h>
using namespace std ;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    int e,f;
    if(b[2]=='F'){
        e=5;
    }
    else{
        e=b[2]-'A';
    }
    if(d[2]=='F'){
        f=5;
    }
    else{
        f=d[2]-'A';
    }
    if((e<=2&&f<=2)||(e>=3&&f>=3)){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        return 0;
    }
    if((e-f)==1||(e-f)==-1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
