#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    int R=b[0]*10+b[1],X=d[0]*10+d[1];
    if(R==X){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    char R2=b[2],X2=d[2];
    if(R2<='C'&&X2<='C'||R2>'D'&&X2>'D'){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }

    if(R2+1==X2||R2-1==X2){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
