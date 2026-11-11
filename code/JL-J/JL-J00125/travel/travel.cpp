#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    int flag=0;
    for(int i=0;i<=1;i++){
        if(b[i]!=d[i]){
            flag++;
        }

    }
    if(flag==0){
        cout<<1;
        if(((b[2]<='C')&&(d[2]<='C'))||((b[2]>='D')&&(d[2]>='D'))){
            cout<<1;
        }
        else{
            cout<<0<<0;
            return 0;
        }
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }
    if(abs(b[2]-d[2])==1){
        cout<<1;
    }
    else{
        cout<<0;
    }

    return 0;
}
