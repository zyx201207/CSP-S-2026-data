#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        printf("0000");
        return 0;
    }else{
        printf("1");
    }
    if(b[0]==d[0]&&b[1]==d[1]){
        printf("1");
    }else{
        printf("000");
        return 0;
    }
    if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='F'&&b[2]<='E'&&d[2]>='F'&&d[2]<='E')){
        printf("1");
    }else{
        printf("00");
        return 0;
    }
    if((b[2]-d[2])==1||(d[2]-b[2])==1){
        printf("1");
    }else{
        printf("0");
    }
    return 0;
}
