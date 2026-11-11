#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",travelin);
    freopen("travel.out","w",travelout);
    string b,d;
    int a,c;
    cin>>a>>b>>c>>d;
    int f=0;
    int e=0;
    int da=1;
    if(a!=c){
        cout<<0;
        da=0;
    }
    else{
        cout<<1;
    }
    int temp=0;
    while(temp<2){
        f=f*10+(b[temp]-'0');
        e=e*10+(d[temp]-'0');
        temp++;
    }
    if(f==e && da==1){
        cout<<1;
        if( ( b[2]<='C' && b[2]>='A' ) && ( d[2]<='C' && d[2]>='A' ) ){
            cout<<1;
        }
        else if( ( b[2]<='F' && b[2]>'C' ) && ( d[2]<='F' && d[2]>'C' ) ){
            cout<<1<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0<<0;
    }
    if( (b[2]=='B' || d[2]=='B') && f==e && da==1 ){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
