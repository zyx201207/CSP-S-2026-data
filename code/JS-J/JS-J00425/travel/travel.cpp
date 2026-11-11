#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string x,y;
    cin>>a>>x>>b>>y;
    if(a==b){
        cout<<1;
    }else {
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(x[0]==y[0]&&x[1]==y[1]){
        cout<<1;
    }else{
        cout<<0<<0<<0;
        return 0;
    }
    if(x[2]>='A'&&x[2]<='C'&&y[2]>='A'&&y[2]<='C'){
        cout<<1;
        if((x[2]==y[2]+1)||(x[2]==y[2]-1))cout<<1;
        else cout<<0;
        return 0;
    }else if((x[2]=='D'&&y[2]=='F')||(x[2]=='F'&&y[2]=='D')){
        cout<<11;
        return 0;
    }else {
        cout<<0<<0;
        return 0;
    }
    return 0;
}
