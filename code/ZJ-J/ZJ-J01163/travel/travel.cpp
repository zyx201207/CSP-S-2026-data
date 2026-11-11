#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool a=0,b=0,c=0,d=0;
    if(c1==c2){
        a=1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    string p1,p2;
    p1=s1[0];
    p1+=s1[1];
    p2=s2[0];
    p2+=s2[1];
    if(p1==p2){
        b=1;
    }
    else{
        cout<<"1000";
        return 0;
    }
    char k1,k2;
    k1=s1[2];
    k2=s2[2];
    if((k1<='C' && k2<='C')||(k1>'C' && k2>'C')){
        c=1;
        int x;
        x=k1-k2;
        if(x==1 || x == -1){
            d=1;
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}