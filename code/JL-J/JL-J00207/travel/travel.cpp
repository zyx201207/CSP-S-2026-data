#include<bits/stdc++.h>
using namespace std;
int main(){
frezopen("travel.in"stdin);
frezopen("travel.out"stdout);
    sting a,b,c,d;
    cin>a>>b>>c>>d;
    if(a!=c){
        cout<<0000;
        break;
    }
    if(b[1]!=d[1]||b[2]!=d[2]){
        cout<<1000;
        break;
    }
    if(b[3]==d[3]+1||d[3]==b[3]+1){
        cout<<1111;
        break;
    }
    cout<<1111;
    return 0;
}
