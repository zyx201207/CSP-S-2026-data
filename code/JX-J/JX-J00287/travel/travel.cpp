#include<bits/stdc++.h>;
#include<iostream>;
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    char b,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0"<<"0"<<"0"<<"0"<<endl;
    }else if(int(b)/100!=int(d)/100){
        cout<<"1"<<"0"<<"0"<<"0"<<endl;
    }else if(int(b)%100<=67 && int(d)%100>=68){
        cout<<"1"<<"1"<<"0"<<"0"<<endl;
    }else if(int(b)%100>=68 && int(d)%100<=67){
        cout<<"1"<<"1"<<"0"<<"0"<<endl;
    }else if(int(b)-int(d)==1||int(b)-int(d)==-1){
        cout<<"1"<<"1"<<"1"<<"0"<<endl;
    }else{
        cout<<"1"<<"1"<<"1"<<"1"<<endl;
    }
    return 0;
}
