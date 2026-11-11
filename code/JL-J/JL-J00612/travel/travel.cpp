#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b,c,d,e;
    cin>>a>>b>>c>>d;
    if((c=="01"||c=="16")||(a=="01"||a=="16")){
        e=e+"0000";
    }
    else if(c==a){
        e=e+'1';
        if(b[1]==d[1]){
            e=e+'1';
        if((b[2]=='C'||d[2]=='C')&&(b[2]=='D'||d[2]=='D')){
            e=e+'0';
        }
        else{
            e=e+'1';
        }
        if((b[2]=='A'||d[2]=='A')&&(b[2]=='B'||d[2]=='B')){
            e=e+"1";
        }
        else if((b[2]=='B'||d[2]=='B')&&(b[2]=='C'||d[2]=='C')){
            e=e+"1";
        }
        else if((b[2]=='F'||d[2]=='F')&&(b[2]=='D'||d[2]=='D')){
            e=e+"1";
        }
        else{
            e=e+'0';
        }
    }
    else{
        e=e+"000";
    }
    }
    else{
        e=e+"0000";
    }
    cout<<e;
    return 0;
}
