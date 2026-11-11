#include<bits/stdc++.h>
using namespace
int m;
cin>>c,s[10000],i,j[10000];
int main(){
    if(c ==i){
        m++;
    }
    else{
        cout<<0000;
    }
    if(s[0]==i[0]&&s[1] ==i[1]&&m==1){
        m++;
    }
    else{
        cout<<1100;
    }
    if(m=2&&s[2]=='D'||'F'&&j[2]=='F'||'D'||s[2]=='A'||'B'||'C'&&j[2]=='A'||'B'||'C'){
        m++;
    }
    else{
        cout<<1110;
    }
    if(m==3&&s[2]=='D'&&j[2]=='F'||s[2]=='F'&&j[2]=='D'||s[2]=='A'&&j[2]=='B'||s[2]=='B'&&j[2]=='A'||s[2]=='B'&&j[2]=='C'||s[2]=='C'&&j[2]=='B'){
        cout<<1111;
    }
    return 0 ;
}

