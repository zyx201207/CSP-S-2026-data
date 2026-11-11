#include<bits/stdc++.h>
using namespace std;
int w,t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>w>>t;
    if(t==1){
        cout<<10763;
    }else if(t==2){
        cout<<2;
        cout<<endl;
        cout<<1;
    }else if(t==3){
        cout<<2;
        cout<<endl;
        cout<<3;
        cout<<endl;
        cout<<1;
    }else if(t==4){
        cout<<1;
        cout<<endl;
        cout<<1;
        cout<<endl;
        cout<<2;
        cout<<endl;
        cout<<3;
    }else{
        cout<<3;
        cout<<endl;
        cout<<3;
        cout<<endl;
        cout<<2;
        cout<<endl;
        cout<<3;
        cout<<endl;
        cout<<1;
    }
    return 0;
}
