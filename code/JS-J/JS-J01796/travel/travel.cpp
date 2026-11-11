#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1==a2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    string c1=b1.substr(0,2);
    string c2=b2.substr(0,2);
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    string d1=b1.substr(2);
    string d2=b2.substr(2);
    if((d1=="C"&&d2=="D")||(d1=="D"&&d2=="C")){
        cout<<"00";
        return 0;
    }else{
        cout<<1;
    }

    if((d1=="D"&&d2=="F")||(d1=="F"&&d2=="D")){
        cout<<1;
    }else if(d1[0]-d2[0]==1||d2[0]-d1[0]==1){
        cout<<1;
    }else{
        cout<<0;
    }






















    return 0;
}
