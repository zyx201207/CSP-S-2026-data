#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(b[0]+b[1]==d[0]+d[1]){
        cout<<1;
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }
    int x=b[2]-'A';
    int y=d[2]-'A';
    int ac=0;
    if(abs(x-y)<=2&&x<=2&&y<=2){
        cout<<1;
        ac=1;
    }
    else{
        if(abs(x-y)<=2&&x>=3&&y>=3&&x<=4&&y<=4){
            cout<<1;
            ac=1;
        }
    }
    if(ac==0){
        cout<<0<<0;
        return 0;
    }
    if(x==y){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
