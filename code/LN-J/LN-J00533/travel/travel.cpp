#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel1.in","r",stdin);
    freopen("travel1.ans","w",stdout);
    char a,b,c,d,o;
    bool x;
    x=true;
    cin>>a>>c>>b>>d;
    if(a[0]==c[0]&&a[1]==c[1]){
        o="1000";
    }else{
        x=flase;
        o="0000";
    }
    if(b[0]==d[0]&&b[1]==d[1]&&x==true){
        o="1100";
    }else{
        x=flase;
        o="1000";
    }
    if(b[2]<='C'&&d[2]<='C'&&x==true){
        if(b[2]=='B'||d[2]=='B'){
            o="1111";
        }else{
            o="1110";
        }
    }else if(b[2]>='D'&&d[2]>='D'&&x=true){
        o="1111";
    }
    cout<<o;
    return 0;
}
