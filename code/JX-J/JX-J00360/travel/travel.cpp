#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,f;
    string sa,sf;
    cin>>a>>sa>>f>>sf;
    int al=(sa[0]-'0')*10+(sa[1]-'0');
    int fl=(sf[0]-'0')*10+(sf[1]-'0');
    char ak=sa[2],fk=sf[2];
    if(a!=f){
        cout<<"0000";
        return 0;
    }    
    cout<<1;
    if(al!=fl){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    if((ak<='C'&&fk>'C')||(ak>'C'&&fk<='C')){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(ak>fk) swap(ak,fk);
    if((ak=='A'&&fk=='B')||(ak=='B'&&fk=='C')||(ak=='D'&&fk=='F')) cout<<1;
    else cout<<0;
    return 0;
}