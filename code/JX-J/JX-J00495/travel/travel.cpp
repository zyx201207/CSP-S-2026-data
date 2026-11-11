#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int m,n;
bool pos;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(b[2]<='C'){
        m=1;
    }
    if(d[2]<='C'){
        n=1;
    }

    if(a==c){
        cout<<1;
        pos=1;
    }
    else{
        cout<<0;
    }


    if(pos && b[0]==d[0] && b[1]==d[1]){
        cout<<1;
    }
    else{
        cout<<0;
    }


    if(pos && b[0]==d[0] && b[1]==d[1]){
        if(m==n){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }


    if(pos && b[0]==d[0] && b[1]==d[1] && m==n && (b[2]==d[2]+1 || b[2]==d[2]-1)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
