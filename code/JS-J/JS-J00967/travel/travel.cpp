#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a[5],b[5],c[5],d[5];
    cin>>a>>b>>c>>d;
    bool f=0;
    for(int i=0;i<2;i++){
        if(a[i]!=c[i]){
            f=1;
        }
    }
    if(!f){
        cout<<1;
    }
    else{
        cout<<0;
    }
    bool ff=0;
    for(int i=0;i<2;i++){
        if(b[i]!=d[i]){
            ff=1;
        }
    }
    if(!ff&&!f){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if((b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C')&&!ff&&!f){
        cout<<1;
    }else{
        cout<<0;
    }
    if(abs(b[2]-d[2])==1&&(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C')&&!ff&&!f){
        cout<<1;
    }else{
        cout<<0;
    }
}
