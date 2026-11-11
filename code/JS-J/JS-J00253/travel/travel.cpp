#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int e,f,g,h;
    char i,j;
    e=(a[1]-'0')+(a[0]-'0')*10;
    f=(c[1]-'0')+(c[0]-'0')*10;
    g=(b[1]-'0')+(b[0]-'0')*10;
    h=(d[1]-'0')+(d[0]-'0')*10;
    i=b[2];
    j=d[2];
    if(e!=f){
        cout<<"0000";
        return 0;
    }
    else if(e==f){
        cout<<"1";
    }
    if(g!=h){
        cout<<"000";
    return 0;
    }
    else if(g==h){
        cout<<"1";
    }
    if((i=='A'&&j=='B')||(i=='A'&&j=='C')||(i=='B'&&j=='C')||(i=='B'&&j=='A')||(i=='C'&&j=='A')||(i=='C'&&j=='B')||(i=='D'&&j=='F')||(i=='F'&&j=='D')){
        cout<<"1";
    }else {
        cout<<"00";
        return 0;
    }
    if((i=='A'&&j=='B')||(i=='B'&&j=='C')||(i=='B'&&j=='A')||(i=='C'&&j=='B')||(i=='C'&&j=='D')||(i=='D'&&j=='F')){
        cout<<"1";
    }
    else cout<<"0";
    return 0;
}
