#include<bits/stdc++.h>
using namespace std;
string n,n2,m,m2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>n2>>m>>m2;
    if(n==m){
        cout<<"1";
    }else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(n2[0]==m2[0]&&n2[1]==m2[1]){
        cout<<"1";
    }else{
        cout<<0<<0<<0;
        return 0;
    }
    if((n2[2]=='A'&&m2[2]=='c')&&(m2[2]=='A'&&n2[2]=='c')){
        cout<<0<<0;
        return 0;
    }
    if((n2[2]=='F'&&m2[2]=='D')||(m2[2]=='F'&&n2[2]=='D')||(m2[2]=='A'&&n2[2]=='B')||(m2[2]=='B'&&n2[2]=='C')||(n2[2]=='A'&&m2[2]=='B')||(n2[2]=='B'&&m2[2]=='C')){
        cout<<"1"<<"1";
    }else{
        cout<<0<<0;
        return 0;
    }
    return 0;
}
